#include "s21_sscanf.h"

#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

// %[*][width][length]specifier
int s21_sscanf(char *str, char *format, ...) {
  setlocale(LC_ALL, "");
  va_list args;
  va_start(args, format);
  int count = 0;
  char *ptr = str;
  while (*format && *str) {
    s21_size_t n_format = s21_strspn(format, "\t\n ");
    s21_size_t n_str = s21_strspn(str, "\t\n ");
    format += n_format;
    str += n_str;
    if (*format == '%')
      format++;
    else {
      while (*str == *format) {
        format = format + 1;
        str++;
      }
      if (*str != *format && *format != '%') break;
      continue;
    }
    Params_scan params = {'\0', -1, 0, '0', 0};
    format = get_scan_params(format, &params);
    if (params.specifier == 'n') {
      format += get_scanned_bytes(&args, str, ptr, params);
    }
    if (format) {
      str = get_arg(&args, str, &params, &count);
    }
  }
  va_end(args);
  return count;
}

char *get_scan_params(char *format, Params_scan *params) {
  char *spec = s21_strpbrk(format, "diuoxXfeEgGcspn%");
  if (!spec) return s21_NULL;
  params->specifier = *spec;  // format specifier
  // Проверить, есть ли звёздочка
  char *asterisk = *format == '*' ? format : s21_NULL;
  if (asterisk) ++params->is_asterisk;
  // Обработка модификаторов формата для длинных/коротких чисел
  char *par;
  if ((par = s21_strchr(format, 'h')) && par < spec) params->length = 'h';
  if ((par = s21_strchr(format, 'L')) && par < spec) params->length = 'L';
  if ((par = s21_strchr(format, 'l')) && par < spec) params->length = 'l';
  if (params->length != '0') ++params->is_length;
  // width numbers digesting
  char *digit =
      ((digit = s21_strpbrk(format, "1234567890")) && digit < spec ? digit
                                                                   : s21_NULL);
  if (digit) params->width = atoi(digit);
  return spec + 1;
}

char *get_arg(va_list *args, char *str, Params_scan *params, int *count) {
  int errors = 0;
  if (s21_strchr("c", params->specifier))
    str = scan_chr(args, str, *params, count);
  if (s21_strchr("diuoxX", params->specifier))
    str = scan_int(args, str, *params, count, &errors);
  if (s21_strchr("feEgG", params->specifier))
    str = scan_flt(args, str, *params, count, &errors);
  if (s21_strchr("s", params->specifier))
    str = scan_str(args, str, *params, count);
  if (s21_strchr("p", params->specifier))
    str = scan_ptr(args, str, *params, count, &errors);
  if (s21_strchr("%", params->specifier)) *(va_arg(*args, char *)) = '%';
  return str;
}

// function handles 'n' specifier - computes number of bytes scanned
int get_scanned_bytes(va_list *args, char *str, char *init_ptr,
                      Params_scan params) {
  if (!params.is_asterisk) {
    if (params.length == 'l') {
      *(va_arg(*args, long *)) = (long)(str - init_ptr);
    } else if (params.length == 'h') {
      *(va_arg(*args, short *)) = (short)(str - init_ptr);
    } else {
      *(va_arg(*args, int *)) = (int)(str - init_ptr);
    }
  }
  char *ptr = s21_strpbrk(str, "n");
  return ptr - str;
}

// in case of 'i' scecifier
// determines the radix of a number which 'str' points to
int define_radix(char *str) {
  int result = 10;  // starting to hate this
  if (*str == '-') str++;
  if (*str == '0') {
    str++;
    if (*str > 47 && *str < 58) {
      result = 8;
    } else if (*str == 'x' || *str == 'X') {
      result = 16;
    }
  }
  return result;
}

int has_scan_fails(char **str, char **result, int *err) {
  if (*str == *result) {
    *err = 1;
    return 1;
  }
  return 0;
}

char *scan_int(va_list *args, char *str, Params_scan params, int *count,
               int *err) {
  char *result;
  // in case when width > 0 a copy of the str is defined. Then,
  // scan_int() is called again with the str_copy as a parameter
  if (params.width > 0) {
    char str_copy[params.width + 1];
    s21_strncpy(str_copy, str, params.width);
    params.width = -1;
    char *local_result = scan_int(args, str_copy, params, count, err);
    result = str + (local_result - str_copy);
    if (*err) return str + s21_strlen(str);
  } else {
    if (s21_strchr("dxXoi", params.specifier)) {
      int radix;
      if (params.specifier == 'd') radix = 10;
      if (params.specifier == 'o') radix = 8;
      if (params.specifier == 'x' || params.specifier == 'X') radix = 16;
      if (params.specifier == 'i') radix = define_radix(str);
      if (params.is_asterisk) {
        strtol(str, &result, radix);
      } else {
        if (params.length == '0') {
          int scan_result = (int)strtol(str, &result, radix);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, int *)) = scan_result;
        }
        if (params.length == 'h') {
          short scan_result = (short)strtol(str, &result, radix);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, short *)) = scan_result;
        }
        if (params.length == 'l') {
          long scan_result = (long)strtol(str, &result, radix);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, long *)) = scan_result;
        }
      }
    }
    if (params.specifier == 'u') {
      if (params.is_asterisk) {
        strtol(str, &result, 10);
        if (str == result) return str + s21_strlen(str);
      } else {
        if (params.length == '0') {
          unsigned int scan_result = (unsigned int)strtoul(str, &result, 10);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, unsigned int *)) = scan_result;
        }
        if (params.length == 'h') {
          unsigned short scan_result =
              (unsigned short)strtoul(str, &result, 10);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, unsigned short *)) = scan_result;
        }
        if (params.length == 'l') {
          unsigned long scan_result = (unsigned long)strtoul(str, &result, 10);
          if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
          (*count)++;
          *(va_arg(*args, unsigned long *)) = scan_result;
        }
      }
    }
  }
  return result;
}

char *scan_chr(va_list *args, char *str, Params_scan params, int *count) {
  char *result = str;
  int counter = *count;
  if (params.length != 'l') {
    if (!params.is_asterisk) {
      *(va_arg(*args, int *)) = str[0];
      // (*count)++;
      ++counter;
    }
    result++;
  } else if (params.length == 'l') {
    wchar_t wc;  // toilet LOOL
    result += mbtowc(&wc, str, s21_strlen(str));
    if (!params.is_asterisk) {
      *(va_arg(*args, wchar_t *)) = wc;
      // (*count)++;
      ++counter;
    }
  }
  *count = counter;
  return result;
}

char *scan_str(va_list *args, char *str, Params_scan params, int *count) {
  char *result = str;
  if (params.length != 'l') {
    s21_size_t n;
    if (params.width > 0) {
      n = params.width;
    } else {
      n = s21_strcspn(str, " \n\t\0");
    }
    if (!params.is_asterisk) {
      char *curr_arg = va_arg(*args, char *);
      s21_memcpy(curr_arg, str, n);
      curr_arg[n] = '\0';
      (*count)++;
    }
    result += n;
  } else if (params.length == 'l') {
    s21_size_t n;
    if (params.width > 0) {
      n = params.width;
    } else
      n = s21_strcspn(str, " \n\t\0");
    if (!params.is_asterisk) {
      if (mbstowcs(va_arg(*args, wchar_t *), str, n) == (s21_size_t)(-1))
        return str + s21_strlen(str);
      (*count)++;
    }
    result += n;
  }
  return result;
}

char *scan_flt(va_list *args, char *str, Params_scan params, int *count,
               int *err) {
  char *result;
  if (params.width > 0) {
    char str_copy[params.width + 1];
    s21_strncpy(str_copy, str, params.width);
    params.width = -1;
    char *local_result = scan_flt(args, str_copy, params, count, err);
    result = str + (local_result - str_copy);
    if (*err) return str + s21_strlen(str);
  } else {
    if (params.is_asterisk) {
      strtold(str, &result);
      if (str == result) return str + s21_strlen(str);
    } else {
      if (params.length == '0') {
        float scan_result = (float)strtof(str, &result);
        if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
        (*count)++;
        *(va_arg(*args, float *)) = scan_result;
      }
      if (params.length == 'l') {
        double scan_result = (double)strtod(str, &result);
        if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
        (*count)++;
        *(va_arg(*args, double *)) = scan_result;
      }
      if (params.length == 'L') {
        long double scan_result = (long double)strtold(str, &result);
        if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
        (*count)++;
        *(va_arg(*args, long double *)) = scan_result;
      }
    }
  }
  return result;
}

char *scan_ptr(va_list *args, char *str, Params_scan params, int *count,
               int *err) {
  char *result;
  if (params.width > 0) {
    char str_copy[params.width + 1];
    s21_strncpy(str_copy, str, params.width);
    params.width = -1;
    char *local_result = scan_ptr(args, str_copy, params, count, err);
    result = str + (local_result - str_copy);
    if (*err) return str + s21_strlen(str);
  } else {
    if (params.is_asterisk) {
      strtoll(str, &result, 16);
      if (str == result) return str + s21_strlen(str);
    } else {
      long long scan_result = (long long)strtoll(str, &result, 16);
      if (has_scan_fails(&str, &result, err)) return str + s21_strlen(str);
      (*count)++;
      *(va_arg(*args, void **)) = (void *)scan_result;
    }
  }
  return result;
}

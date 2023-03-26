#include "s21_sprintf.h"

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_strerror.h"
#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  setlocale(LC_ALL, "");
  va_list args;
  va_start(args, format);
  str[0] = '\0';
  while (format) {
    int n = s21_strcspn(format, "%");
    s21_strncat(str, format, n);
    format += n;
    if (*format == '%') ++format;
    Flags f = {0};
    Params p = {'\0', f, '0', 0, 0, 0, 0, 0};
    format = get_params(format, &p, &args);
    if (format) {
      arg_to_str(&args, str + s21_strlen(str), &p);
      if (p.specifier == 'n') len_to_arg(&args, str, &p);
    }
  }
  va_end(args);
  return s21_strlen(str);
}

// Обработка спецификации формата
const char *get_params(const char *format, Params *p, va_list *args) {
  const char *spec = s21_strpbrk(format, "diuoxXfeEgGcspn%");
  if (!spec) return s21_NULL;
  p->specifier = *spec;
  char *par;
  if ((par = s21_strchr(format, '-')) && par < spec) ++p->f.minus;
  if ((par = s21_strchr(format, '+')) && par < spec) ++p->f.plus;
  if ((par = s21_strchr(format, ' ')) && par < spec) ++p->f.space;
  if ((par = s21_strchr(format, '#')) && par < spec) ++p->f.sharp;
  // if ((par = strchr(format, '0')) && par < spec) ++p->f.zero;
  if ((par = s21_strchr(format, 'h')) && par < spec) p->width = 'h';
  if ((par = s21_strchr(format, 'l')) && par < spec) p->width = 'l';
  if ((par = s21_strchr(format, 'L')) && par < spec) p->width = 'L';
  if (p->width) ++p->is_width;
  if (s21_strchr("diuoxXp", p->specifier)) p->accuracy = 1;
  if (s21_strchr("feEgG", p->specifier)) p->accuracy = 6;
  if (s21_strchr("s", p->specifier)) p->accuracy = INT_MAX;
  char *dot = ((dot = s21_strchr(format, '.')) && dot < spec ? dot : s21_NULL);
  char *asterisk =
      ((asterisk = s21_strchr(format, '*')) && asterisk < spec ? asterisk
                                                               : s21_NULL);
  char *digit =
      ((digit = s21_strpbrk(format, "123456789")) && digit < spec ? digit
                                                                  : s21_NULL);
  if (!dot)
    p->f.zero =
        ((par = s21_strchr(format, '0')) && (digit ? par < digit : par < spec));
  else
    p->f.zero = ((par = s21_strchr(format, '0')) &&
                 (digit ? (par < digit) && (par < dot) : par < dot));
  // Обработка минимальной ширины поля
  if (!dot && (asterisk || digit)) {
    p->length = (asterisk ? va_arg(*args, int) : atoi(digit));
    if (p->length) ++p->is_length;
  }
  if (dot) p->is_accuracy = p->is_length = 1;
  if (dot && !asterisk && !digit) p->accuracy = 0;
  if (dot && (asterisk || digit)) {
    if (asterisk && asterisk < dot)
      p->length = va_arg(*args, int);
    else if (digit && digit < dot)
      p->length = atoi(digit);
    asterisk =
        ((asterisk = s21_strchr(dot, '*')) && asterisk < spec ? asterisk
                                                              : s21_NULL);
    digit =
        ((digit = s21_strpbrk(dot, "0123456789")) && digit < spec ? digit
                                                                  : s21_NULL);
    if (asterisk || digit)
      p->accuracy = (asterisk ? va_arg(*args, int) : atoi(digit));
    if (!asterisk && !digit) p->accuracy = 0;
  }
  // print_params(p);
  return ++spec;
}

char *arg_to_str(va_list *args, char *str, Params *p) {
  if (s21_strchr("c", p->specifier)) chr_to_str(args, str, p);
  if (s21_strchr("diuoxX", p->specifier)) int_to_str(args, str, p);
  if (s21_strchr("s", p->specifier)) str_to_str(args, str, p);
  if (s21_strchr("feEgG", p->specifier)) flt_to_str(args, str, p);
  if (s21_strchr("p", p->specifier)) ptr_to_str(args, str, p);
  if (s21_strchr("%", p->specifier)) s21_strcat(str, "%");
  return str;
}

char *chr_to_str(va_list *args, char *str, Params *p) {
  if (p->width == '0') {
    str[0] = va_arg(*args, int);
    str[1] = '\0';
  }
  if (p->width == 'l') {
    wchar_t wc = va_arg(*args, wchar_t);
    int n = wctomb(str, wc);
    str[n] = '\0';
  }
  // Дополнение пробелами до необходимой ширины и выравнивание по краю
  s21_strchrncat(str, ' ', p->length - s21_strlen(str), p->f.minus);
  return str;
}

// Строки
char *str_to_str(va_list *args, char *str, Params *p) {
  if (p->width == '0') s21_strncat(str, va_arg(*args, char *), p->accuracy);
  if (p->width == 'l') {
    wchar_t *pwcs = va_arg(*args, wchar_t *);
    int n = wcstombs(str, pwcs, wcslen(pwcs) * MB_CUR_MAX);
    if (p->accuracy < n) n = p->accuracy;
    str[n] = '\0';
  }
  // Дополнение пробелами до необходимой ширины и выравнивание по краю
  s21_strchrncat(str, ' ', p->length - s21_strlen(str), p->f.minus);
  return str;
}

char *int_to_str(va_list *args, char *str, Params *p) {
  long long arg = 0;
  if (s21_strchr("di", p->specifier)) {
    if (p->width == '0') arg = (int)va_arg(*args, int);
    if (p->width == 'h') arg = (short)va_arg(*args, int);
    if (p->width == 'l') arg = (long)va_arg(*args, long);
  }
  if (s21_strchr("uoxX", p->specifier)) {
    if (p->width == '0') arg = (unsigned int)va_arg(*args, unsigned int);
    if (p->width == 'h') arg = (unsigned short)va_arg(*args, unsigned int);
    if (p->width == 'l') arg = (unsigned long)va_arg(*args, unsigned long);
  }
  s21_itoa(
      arg, str,
      s21_strchr("xX", p->specifier) ? 16 : (p->specifier == 'o' ? 8 : 10));
  if (arg == 0 && p->accuracy == 0) str[0] = '\0';
  if (s21_strchr("X", p->specifier))
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
  // Дополнение ширины поля нулями
  s21_strchrncat(str, '0', p->accuracy - s21_strlen(str), 0);
  int k = 0;  // Количество знаков в итоговом префиксе
  if (p->f.sharp && s21_strchr("xX", p->specifier) && arg != 0) {
    s21_strchrncat(str, p->specifier, 1, 0);
    s21_strchrncat(str, '0', (k += 2, 1), 0);
  }
  // Префикс 0 перед 8-м числом
  if (p->f.sharp && s21_strchr("o", p->specifier) && arg != 0 && (*str != '0'))
    s21_strchrncat(str, '0', 1, 0);
  if (arg < 0) s21_strchrncat(str, '-', (++k, 1), 0);
  if (p->f.plus && arg >= 0 && s21_strchr("di", p->specifier))
    s21_strchrncat(str, '+', (++k, 1), 0);
  if (p->f.space && !p->f.plus && arg >= 0 && s21_strchr("di", p->specifier))
    s21_strchrncat(str, ' ', (++k, 1), 0);
  // Дополнение пробелами до необходимой ширины и выравнивание по краю
  char ch = (p->f.zero && !p->f.minus && p->is_length ? '0' : ' ');
  s21_strchrncat(str + (ch == '0' ? k : 0), ch, p->length - s21_strlen(str),
                 p->f.minus);
  return str;
}

char *flt_to_str(va_list *args, char *str, Params *p) {
  long double arg = 0;
  if (p->width == '0') arg = (double)va_arg(*args, double);
  if (p->width == 'h') arg = (float)va_arg(*args, double);
  if (p->width == 'l') arg = (double)va_arg(*args, double);
  if (p->width == 'L') arg = (long double)va_arg(*args, long double);
  long double mantissa = arg;  // Мантисса аргумента
  int n = 0;
  if (arg != arg || arg == 1.0 / 0.0 || arg == -1.0 / 0.0) {
    if (arg < 0) s21_strcat(str, "-");
    if (arg != arg)
      s21_strcat(str, "nan");
    else
      s21_strcat(str, "inf");
    if (s21_strchr("GE", p->specifier))
      for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    return str;
  }
  if (s21_strchr("eEgG", p->specifier)) {
    while (fabsl(mantissa) >= 10) {
      mantissa /= 10;
      n++;
    }
    while (0 < fabsl(mantissa) && fabsl(mantissa) < 1) {
      mantissa *= 10;
      n--;
    }
  }
  int f_exp = (n < -4 || n >= p->accuracy);
  if (0 == arg || (1 <= arg && arg <= 9)) f_exp = 0;
  if (s21_strchr("f", p->specifier)) s21_ftoa(arg, str, p->accuracy, 0);
  if (s21_strchr("eE", p->specifier)) s21_ftoa(mantissa, str, p->accuracy, 0);
  if (s21_strchr("gG", p->specifier))
    s21_ftoa(f_exp ? mantissa : arg, str, p->accuracy, 1);
  if (s21_strchr("gG", p->specifier) && !p->f.sharp) {
    char *dot = s21_strchr(str, '.');
    for (char *p;
         dot && (p = s21_strrchr(dot, '0')) && !s21_strpbrk(p, "123456789");)
      *p = '\0';
    if (dot && !s21_strpbrk(dot, "0123456789")) *dot = '\0';
  }
  int k = 0;  // Количество знаков в итоговом префиксе
  if (arg < 0) s21_strchrncat(str, '-', (++k, 1), 0);
  if (p->f.plus && arg >= 0) s21_strchrncat(str, '+', (++k, 1), 0);
  if (p->f.space && !p->f.plus && arg >= 0)
    s21_strchrncat(str, ' ', (++k, 1), 0);
  if (p->f.sharp && p->accuracy == 0) s21_strcat(str, ".");
  if (s21_strchr("eE", p->specifier) ||
      (s21_strchr("gG", p->specifier) && f_exp)) {
    s21_strchrncat(str, (isupper(p->specifier) ? 'E' : 'e'), 1, 1);
    s21_strchrncat(str, (n >= 0 ? '+' : '-'), 1, 1);
    s21_strchrncat(str, '0', abs(n) < 9, 1);
    s21_itoa(n, str + s21_strlen(str), 10);
  }
  // Дополнение пробелами до необходимой ширины и выравнивание по краю
  char ch = (p->f.zero && !p->f.minus ? '0' : ' ');
  s21_strchrncat(str + (ch == '0' ? k : 0), ch, p->length - s21_strlen(str),
                 p->f.minus);
  return str;
}

char *ptr_to_str(va_list *args, char *str, Params *p) {
  void *arg = va_arg(*args, void *);
  if (arg == s21_NULL) {
    s21_strcat(str, S21_NIL);
    return str;
  }
  s21_itoa((long long)arg, str, 16);
  if (arg == 0 && p->accuracy == 0) str[0] = '\0';
  s21_strchrncat(str, '0', p->accuracy - s21_strlen(str), 0);
  s21_strchrncat(str, 'x', 1, 0);
  int k = 0;
  s21_strchrncat(str, '0', (k += 2, 1), 0);
  // Дополнение пробелами до необходимой ширины и выравнивание по краю
  char ch =
      (p->f.zero && !p->f.minus && p->is_width && !p->is_accuracy ? '0' : ' ');
  s21_strchrncat(str + (ch == '0' ? k : 0), ch, p->length - s21_strlen(str),
                 p->f.minus);
  return str;
}

s21_size_t len_to_arg(va_list *args, char *str, Params *p) {
  if (p->width == '0') {
    int *pArg = va_arg(*args, int *);
    *pArg = (int)s21_strlen(str);
  }
  if (p->width == 'h') {
    short *pArg = va_arg(*args, short *);
    *pArg = (short)s21_strlen(str);
  }
  if (p->width == 'l') {
    long *pArg = va_arg(*args, long *);
    *pArg = (long)s21_strlen(str);
  }
  return s21_strlen(str);
}

char *s21_strchrncat(char *str, char ch, int n, int f) {
  if (n <= 0) return str;
  s21_size_t m = s21_strlen(str);
  if (f) {
    s21_memset(str + m, ch, n);
    str[m + n] = '\0';
  } else {
    s21_memmove(str + n, str, m + 1);
    s21_memset(str, ch, n);
  }
  return str;
}

char *s21_itoa(long long value, char *str, int radix) {
  char *buffer = str;
  value = llabs(value);
  do {
    *buffer = value % radix + (value % radix < 10 ? 48 : 87);
    ++buffer;
    value /= radix;
  } while (value != 0);
  *buffer = '\0';
  --buffer;
  for (int i = 0; (str + i) < (buffer - i); ++i) {
    char temp = *(str + i);
    *(str + i) = *(buffer - i);
    *(buffer - i) = temp;
  }
  return str;
}

char *s21_ftoa(long double value, char *str, s21_size_t accuracy, int f) {
  char *p, *digit;
  s21_size_t n = (f ? 0 : accuracy);
  value = fabsl(value);
  do {
    long double a, b;
    b = modfl(roundl(value * pow(10, n)) / pow(10, n), &a);
    s21_itoa(llroundl(a), str, 10);
    p = str + s21_strlen(str);
    if (n > 0) s21_itoa(llroundl(b * pow(10, n)), p, 10);
    s21_strchrncat(p, '0', n++ - s21_strlen(p), 0);
    if (f && value == 0 && n == accuracy) break;
    digit = s21_strpbrk(str, "123456789");
  } while (f && (!digit || s21_strlen(digit) < accuracy));
  s21_strchrncat(p, '.', (--n > 0), 0);
  return str;
}
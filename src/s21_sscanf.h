#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>
#include <stdlib.h>

#define S21_NIL "0x0"

typedef struct {
  char specifier;
  int width;        // Max quantity of chars to read
                    // If (width < 0) => width not specified
  int is_asterisk;  // Наличие '*' sign
  char length;  // Формат длинных/коротких чисел h/l/L
  int is_length;  // Наличие этого формата
} Params_scan;

char *get_arg(va_list *args, char *str, Params_scan *params, int *count);
char *get_scan_params(char *format, Params_scan *params);
int s21_sscanf(char *str, char *format, ...);
char *scan_int(va_list *args, char *str, Params_scan params, int *count,
               int *err);
char *scan_flt(va_list *args, char *str, Params_scan params, int *count,
               int *err);
int define_radix(char *str);
int has_scan_fails(char **str, char **result, int *err);
char *scan_ptr(va_list *args, char *str, Params_scan params, int *count,
               int *err);
char *scan_chr(va_list *args, char *str, Params_scan params, int *count);
char *scan_str(va_list *args, char *str, Params_scan params, int *count);
int get_scanned_bytes(va_list *args, char *str, char *init_ptr,
                      Params_scan params);

#endif  // S21_SSCANF_H;

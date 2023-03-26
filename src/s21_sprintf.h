#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stdlib.h>

#define S21_NIL "0x0"

typedef struct {
  unsigned int minus : 1;
  unsigned int plus : 1;
  unsigned int space : 1;
  unsigned int sharp : 1;
  unsigned int zero : 1;
} Flags;

typedef struct {
  char specifier;
  Flags f;
  char width;       // Формат длинных/коротких чисел
  int is_width;     // Наличие этого формата
  int accuracy;     // Точность
  int is_accuracy;  // Наличие точности
  int length;       // Min ширина поля
  int is_length;    // Наличие min ширины поля
} Params;

int s21_sprintf(char *str, const char *format, ...);
const char *get_params(const char *format, Params *p, va_list *args);
char *arg_to_str(va_list *args, char *str, Params *p);
size_t len_to_arg(va_list *args, char *str, Params *p);
char *chr_to_str(va_list *args, char *str, Params *p);
char *str_to_str(va_list *args, char *str, Params *p);
char *int_to_str(va_list *args, char *str, Params *p);
char *flt_to_str(va_list *args, char *str, Params *p);
char *ptr_to_str(va_list *args, char *str, Params *p);
char *s21_strchrncat(char *str, char ch, int n, int f);
char *s21_itoa(long long value, char *str, int radix);
char *s21_ftoa(long double value, char *str, size_t accuracy, int f);

#endif  // S21_SPRINTF_H;
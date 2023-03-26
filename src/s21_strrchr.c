#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t i = s21_strlen(str);
  while (i != 0 && str[i] != c) --i;
  return c == str[i] ? (char *)str + i : s21_NULL;
}

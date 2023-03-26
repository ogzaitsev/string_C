#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] && str[i] != c) ++i;
  return c == str[i] ? (char *)str + i : NULL;
}

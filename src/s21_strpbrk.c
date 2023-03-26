#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *scanp;
  int c, sc;
  while ((c = *str1++) != 0) {
    for (scanp = str2; (sc = *scanp++) != '\0';)
      if (sc == c) return ((char *)(str1 - 1));
  }
  return (s21_NULL);
}

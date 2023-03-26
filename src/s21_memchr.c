#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buf = (unsigned char *)str;
  unsigned char *res = s21_NULL;
  int stop = 0;
  while (!stop && (str != s21_NULL) && (n--)) {
    if (*buf != (unsigned char)c) {
      buf++;
    } else {
      res = buf;
      stop = 1;
    }
  }
  return res;
}
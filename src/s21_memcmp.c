#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int diff = 0;
  for (s21_size_t i = 0; i < n && diff == 0; i++) {
    diff = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
  }
  return diff;
}

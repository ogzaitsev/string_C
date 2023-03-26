#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (src < dest) {
    for (s21_size_t i = n; i != 0; i--)
      ((char *)dest)[i - 1] = ((char *)src)[i - 1];
  } else {
    for (s21_size_t i = 0; i < n; i++) ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

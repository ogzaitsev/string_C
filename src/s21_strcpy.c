#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t size = s21_strlen(src);
  for (s21_size_t i = 0; i < size; i++) {
    dest[i] = src[i];
  }
  dest[size] = '\0';
  return dest;
}

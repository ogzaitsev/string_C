#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_strcmp(const char *string1, const char *string2) {
  s21_size_t max = SIZE_MAX;
  int result = 0;
  int stop = 0;
  for (s21_size_t i = 0; !stop && i < max; i++) {
    char c1 = string1[i];
    char c2 = string2[i];
    result = c1 - c2;
    if (result != 0 || c1 == '\0' || c2 == '\0') {
      stop = 1;
    }
  }
  return result;
}

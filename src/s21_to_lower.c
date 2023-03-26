#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;
  int size = s21_strlen(str);
  if (str) {
    result = (char *)realloc(result, size + 1);
    result[size] = '\0';
  }
  if (result) {
    s21_strcpy(result, str);
    for (int i = 0; i < size; i++) {
      if (result[i] >= 'A' && result[i] <= 'Z') result[i] += 32;
    }
  }
  return result;
}

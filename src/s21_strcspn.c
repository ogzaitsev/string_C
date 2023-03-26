#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t size = 0;
  int check = 0;
  for (s21_size_t i = 0; !check && i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; !check && j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) check = 1;
    }
    if (check != 1) size++;
  }
  return size;
}

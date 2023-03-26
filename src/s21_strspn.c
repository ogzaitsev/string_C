#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

s21_size_t s21_strspn(const char *string, const char *chars) {
  s21_size_t result = 0;
  s21_size_t chars_length = s21_strlen(chars);
  int i = 0;
  int match = 1;
  while (match == 1) {
    match = 0;
    for (s21_size_t j = 0; j < chars_length; j++) {
      if (string[i] == chars[j]) {
        result++;
        match = 1;
        break;
      }
    }
    i++;
    if (string[i] == '\0') {
      break;
    }
  }
  return result;
}

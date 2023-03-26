#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = NULL;
  s21_size_t size1 = s21_strlen(haystack);
  s21_size_t size2 = s21_strlen(needle);

  if (size1 >= size2) {
    for (s21_size_t i = 0; i <= size1 - size2; i++) {
      int check = 1;
      for (int j = i, n = 0; needle[n]; j++, n++) {
        if (haystack[j] != needle[n]) {
          check = 0;
          break;
        }
      }
      if (check) {
        result = (char *)haystack + i;
        break;
      }
    }
  }
  return result;
}

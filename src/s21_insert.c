#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_res = len_src + len_str;

  if (src && len_str && start_index <= len_src) {
    result = realloc(result, len_res + 1);
    s21_size_t i = 0;
    for (; i < start_index; i++) {
      result[i] = src[i];
    }
    s21_size_t j = i;
    for (s21_size_t k = 0; j < i + len_str; j++, k++) {
      result[j] = str[k];
    }
    for (; j < len_src + len_str; j++, i++) {
      result[j] = src[i];
    }
    result[len_res] = '\0';
  }
  return (void *)result;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *prev;
  char *ans = s21_NULL;
  if (str == s21_NULL) {
    str = prev;
  }
  s21_size_t i = 0;
  int flag = 1;
  // skip str chars if they equal to delim
  for (; str[i] && flag; i++) {
    flag = 0;
    for (s21_size_t j = 0; delim[j]; j++) {
      if (str[i] == delim[j]) {
        flag = 1;
      }
    }
  }
  if (i > 0 && flag == 0) {
    ans = &str[--i];
  }
  // compare str chars to chars from delim: if true - set \0 and stop
  for (flag = 1; str[i] && flag; i++) {
    for (s21_size_t j = 0; delim[j] && flag; j++) {
      if (str[i] == delim[j]) {
        flag = 0;
        str[i] = '\0';
      }
    }
  }
  prev = &str[i];
  return ans;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strerror(int errnum) {
  char err_list[][THE_LONGEST] = ERRLIST;
  static char err_descr[THE_LONGEST + 12];  // 11 digits of INT_MIN and 1 space
  s21_size_t i = 0;
  if (errnum >= 0 && errnum < ERROR_N) {
    for (; err_list[errnum][i]; i++) {
      err_descr[i] = err_list[errnum][i];
    }
  } else {
    for (; i < STR_ERROR_LEN; i++) {
      err_descr[i] = STR_ERROR[i];
    }
    // writing the unknown error code
    err_descr[i] = ' ';
    int minus_flag = 0;
    if (errnum < 0) {
      minus_flag = 1;
      errnum *= -1;
      err_descr[++i] = '-';
    }
    while (errnum != 0) {
      int last_dig = errnum % 10;
      err_descr[++i] = last_dig + 48;
      errnum /= 10;
    }
    // reverse
    int l = STR_ERROR_LEN + 1 + minus_flag, r = i;
    for (int j = 0; j < (r - l) / 2 + 1; j++) {
      char tmp = err_descr[l + j];
      err_descr[l + j] = err_descr[r - j];
      err_descr[r - j] = tmp;
    }
    i++;
  }
  // clear static array from previous usage
  for (; i < THE_LONGEST + 12; i++) {
    err_descr[i] = '\0';
  }
  return err_descr;
}

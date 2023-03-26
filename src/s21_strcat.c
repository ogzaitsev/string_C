#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *ptr = dest + s21_strlen(dest);
  while (*src != '\0') {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}

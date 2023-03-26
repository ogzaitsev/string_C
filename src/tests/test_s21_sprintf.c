#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"

#define BUFF_SIZE 512

// %d

START_TEST(test_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %d";
  int val = 49;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%5d";
  int val = 79;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5d";
  int val = -69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-05d";
  int val = -59;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%+12d";
  int val = -99;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% *d";
  int val = 39;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 109;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 6, val, -18935, 15, 6361, 0, -749376201),
      sprintf(str2, format, 6, val, -18935, 15, 6361, 0, -749376201));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%hd";
  short int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %i

START_TEST(test_11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %i";
  int val = 79;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5i";
  int val = 59;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_13) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-7i";
  int val = 49;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%013i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0.*i";
  int val = 89;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%+5.31li";
  long int val = 948573613843;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-16.9hi";
  short int val = 9485;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %u

START_TEST(test_18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%u";
  unsigned int val = 84731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15u";
  unsigned int val = 84731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-16u";
  unsigned int val = 84731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_21) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.51u";
  unsigned int val = 84731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_22) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% 5.51u";
  unsigned int val = 84731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_23) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%hu";
  unsigned short int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lu";
  unsigned long int val = 998734615385;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 998734615385;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %o

START_TEST(test_26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%17o";
  int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-16o";
  int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.51o";
  int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.51o";
  int val = 14731;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#o";
  int val = 83675;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lo";
  long int val = 998734615385;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 998734615385;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_34) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lo";
  long int val = 95798;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %x

START_TEST(test_35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%5x";
  unsigned val = 937564812;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#-10x";
  unsigned val = 937564812;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15x";
  unsigned val = 937564812;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 937564812;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#-5.10x";
  unsigned val = 937564812;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#x";
  unsigned val = 93645;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#hx";
  unsigned short val = 18765;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#lx";
  unsigned long val = 93756481274985;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_45) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %c

START_TEST(test_46) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%c";
  char val = 'Y';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_47) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5c";
  char val = 'w';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_48) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% -5c";
  char val = 'u';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_49) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15c";
  char val = 'q';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_50) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.3c%c%c%c%c Hey, there. You're pretty!";
  char val = 'h';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'e', 'l', 'l', 'o'),
                   sprintf(str2, format, val, 'e', 'l', 'l', 'o'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_51) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.3c";
  char val = 'z';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_52) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.3lc";
  char val = 'z';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_53) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple wide char %lc";
  unsigned long w = L'汉';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

// %s

START_TEST(test_54) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s";
  char *val = "OMG, how many more tests do I have to write?..";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_55) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.14s";
  char *val = "OMG, how many more tests do I have to write?..";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_56) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15s";
  char *val = "I'm a bit tired, to be honest...";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_57) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-15.9s";
  char *val = "But I'll power through...";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_58) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s";
  char *val =
      "'Cause that's life and you're supposed to power through, NO MATTER WHAT";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_60) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s%s%s%s";
  char *val =
      "'Cause that's life and you're supposed to power through, NO MATTER WHAT";
  char *s1 = "";
  char *s2 = "30957235634175789235908-2`895378134";
  char *s3 = "someMOREmeaninglessTEXT";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_61) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "SomerandomTEXTtocheckSMTH";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %f

START_TEST(test_62) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 785364.947365295748018;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_63) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 78.59;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_64) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 66.33;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_65) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 12.67;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_66) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 83.11;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_67) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -68.98765430;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_68) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 947623984632.6847935;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_69) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_70) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 7958732.047865;
  float val3 = 8.3;
  double val4 = 9964.84673;
  long double val5 = 947623984632.947623984632;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %e

START_TEST(test_71) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.18Le";
  long double val = 83.11;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_72) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 34.56;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_73) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 13.000009013;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_74) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.16Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_75) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -12.97485623;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_76) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 94758372641.0580364;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_77) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%018E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_78) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%18e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_79) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 7958732.047865;
  float val3 = 8.3;
  double val4 = 9964.84673;
  long double val5 = 947623984632.947623984632;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_80) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.18LE";
  long double val = 7904736;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %g

START_TEST(test_81) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 0.80003;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_82) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 9876.64983;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_83) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 0.100023;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_84) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double v = 0.100023;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_85) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double v = 0.100023;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_86) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double v = 0.100023;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_87) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double v = 0.00005;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_88) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_89) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double v = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_90) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 0.0000007;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_91) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double v = 0.0000007;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_92) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 0.006;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_93) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double v = 0.000009;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_94) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double v = 0.000004;
  double v1 = 41.1341;
  double v2 = 848.9000;
  long double v3 = 0.0843;
  double v4 = 0.0005;
  double v5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, v, v1, v2, v3, v4, v5),
                   sprintf(str2, format, v, v1, v2, v3, v4, v5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_95) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double v = 9.00000;
  ck_assert_int_eq(s21_sprintf(str1, format, v), sprintf(str2, format, v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %p

START_TEST(test_96) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_97) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_98) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_99) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_100) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%p";
  char *ptr = "some ptr";
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// %n

START_TEST(test_101) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int num = 0;
  char *format =
      "Hi, my dear friend! Let's check this shit together, shall we? %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &num),
                   sprintf(str2, format, &num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_102) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int num = 0;
  char *format =
      "Hi, my dear friend! %n Let's check this shit together, shall we?";
  ck_assert_int_eq(s21_sprintf(str1, format, &num),
                   sprintf(str2, format, &num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_103) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int num = 0;
  char *format =
      "%nHi, my dear friend! Let's check this shit together, shall we?";
  ck_assert_int_eq(s21_sprintf(str1, format, &num),
                   sprintf(str2, format, &num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_104) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long int num = 0;
  char *format =
      "Hi, my dear friend! %ln Let's check this shit together, shall we?";
  ck_assert_int_eq(s21_sprintf(str1, format, &num),
                   sprintf(str2, format, &num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_105) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  short int num = 0;
  char *format =
      "Hi, my dear friend! %hn Let's check this shit together, shall we?";
  ck_assert_int_eq(s21_sprintf(str1, format, &num),
                   sprintf(str2, format, &num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Some more tests

START_TEST(test_106) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int i = 5;
  char *format = "%*.3Lf";
  long double val = 947623984632.6847935;
  ck_assert_int_eq(s21_sprintf(str1, format, i, val),
                   sprintf(str2, format, i, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_107) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %d-";
  int val = 49;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_108) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %d+";
  int val = 49;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_109) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %+-5f";
  float val = 49.5697809;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_110) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %5hf";
  float val = 49.5697809;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "this is nan test %.19LE %.19Le %.19LG %.19Lg :)";
  long double val = 0.0 / 0.0;
  unsigned long long L =
      (*((unsigned long long *)&val)) & ~((unsigned long long)1 << 63);
  val = *((double *)&L);
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val),
                   sprintf(str2, format, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_112) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "this is +inf test %.19LE %.19Le %.19LG %.19Lg :)";
  long double val = INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val),
                   sprintf(str2, format, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_113) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "this is -inf test %.19LE %.19Le %.19LG %.19Lg :)";
  long double val = -INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val),
                   sprintf(str2, format, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  setlocale(LC_ALL, "en_US.utf8");
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");
  tc_core = tcase_create("Core");

  // %d
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  tcase_add_test(tc_core, test_9);
  tcase_add_test(tc_core, test_10);
  // %i
  tcase_add_test(tc_core, test_11);
  tcase_add_test(tc_core, test_12);
  tcase_add_test(tc_core, test_13);
  tcase_add_test(tc_core, test_14);
  tcase_add_test(tc_core, test_15);
  tcase_add_test(tc_core, test_16);
  tcase_add_test(tc_core, test_17);
  // %u
  tcase_add_test(tc_core, test_18);
  tcase_add_test(tc_core, test_19);
  tcase_add_test(tc_core, test_20);
  tcase_add_test(tc_core, test_21);
  tcase_add_test(tc_core, test_22);
  tcase_add_test(tc_core, test_23);
  tcase_add_test(tc_core, test_24);
  tcase_add_test(tc_core, test_25);
  // %o
  tcase_add_test(tc_core, test_26);
  tcase_add_test(tc_core, test_27);
  tcase_add_test(tc_core, test_28);
  tcase_add_test(tc_core, test_29);
  tcase_add_test(tc_core, test_30);
  tcase_add_test(tc_core, test_31);
  tcase_add_test(tc_core, test_32);
  tcase_add_test(tc_core, test_33);
  tcase_add_test(tc_core, test_34);
  // %x
  tcase_add_test(tc_core, test_35);
  tcase_add_test(tc_core, test_36);
  tcase_add_test(tc_core, test_37);
  tcase_add_test(tc_core, test_38);
  tcase_add_test(tc_core, test_39);
  tcase_add_test(tc_core, test_40);
  tcase_add_test(tc_core, test_41);
  tcase_add_test(tc_core, test_42);
  tcase_add_test(tc_core, test_43);
  tcase_add_test(tc_core, test_44);
  tcase_add_test(tc_core, test_45);
  // %c
  tcase_add_test(tc_core, test_46);
  tcase_add_test(tc_core, test_47);
  tcase_add_test(tc_core, test_48);
  tcase_add_test(tc_core, test_49);
  tcase_add_test(tc_core, test_50);
  tcase_add_test(tc_core, test_51);
  tcase_add_test(tc_core, test_52);
  tcase_add_test(tc_core, test_53);
  // %s
  tcase_add_test(tc_core, test_54);
  tcase_add_test(tc_core, test_55);
  tcase_add_test(tc_core, test_56);
  tcase_add_test(tc_core, test_57);
  tcase_add_test(tc_core, test_58);
  tcase_add_test(tc_core, test_60);
  tcase_add_test(tc_core, test_61);
  // %f
  tcase_add_test(tc_core, test_62);
  tcase_add_test(tc_core, test_63);
  tcase_add_test(tc_core, test_64);
  tcase_add_test(tc_core, test_65);
  tcase_add_test(tc_core, test_66);
  tcase_add_test(tc_core, test_67);
  tcase_add_test(tc_core, test_68);
  tcase_add_test(tc_core, test_69);
  tcase_add_test(tc_core, test_70);
  // %e
  tcase_add_test(tc_core, test_71);
  tcase_add_test(tc_core, test_72);
  tcase_add_test(tc_core, test_73);
  tcase_add_test(tc_core, test_74);
  tcase_add_test(tc_core, test_75);
  tcase_add_test(tc_core, test_76);
  tcase_add_test(tc_core, test_77);
  tcase_add_test(tc_core, test_78);
  tcase_add_test(tc_core, test_79);
  tcase_add_test(tc_core, test_80);
  // %g
  tcase_add_test(tc_core, test_81);
  tcase_add_test(tc_core, test_82);
  tcase_add_test(tc_core, test_83);
  tcase_add_test(tc_core, test_84);
  tcase_add_test(tc_core, test_85);
  tcase_add_test(tc_core, test_86);
  tcase_add_test(tc_core, test_87);
  tcase_add_test(tc_core, test_88);
  tcase_add_test(tc_core, test_89);
  tcase_add_test(tc_core, test_90);
  tcase_add_test(tc_core, test_91);
  tcase_add_test(tc_core, test_92);
  tcase_add_test(tc_core, test_93);
  tcase_add_test(tc_core, test_94);
  tcase_add_test(tc_core, test_95);
  // %p
  tcase_add_test(tc_core, test_96);
  tcase_add_test(tc_core, test_97);
  tcase_add_test(tc_core, test_98);
  tcase_add_test(tc_core, test_99);
  tcase_add_test(tc_core, test_100);
  // %n
  tcase_add_test(tc_core, test_101);
  tcase_add_test(tc_core, test_102);
  tcase_add_test(tc_core, test_103);
  tcase_add_test(tc_core, test_104);
  tcase_add_test(tc_core, test_105);
  // Some more tests
  tcase_add_test(tc_core, test_106);
  tcase_add_test(tc_core, test_107);
  tcase_add_test(tc_core, test_108);
  tcase_add_test(tc_core, test_109);
  tcase_add_test(tc_core, test_110);
  // nan and +-inf situations
  tcase_add_test(tc_core, test_111);
  tcase_add_test(tc_core, test_112);
  tcase_add_test(tc_core, test_113);

  suite_add_tcase(s, tc_core);

  return s;
}

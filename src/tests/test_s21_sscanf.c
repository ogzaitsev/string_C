#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_sscanf.h"

#define BUFF_SIZE 512

// %d

START_TEST(test_1) {
  int num1 = 0, num2 = 0;
  char *string = "-69";
  char *format = "%d";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_2) {
  int num1 = 0, num2 = 0;
  char *string = "497849";
  char *format = "%5d";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_3) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%05d";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_4) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%hd";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_5) {
  long num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%ld";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

// %i
START_TEST(test_6) {
  int num1 = 0, num2 = 0;
  char *string = "69";
  char *format = "%i";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_7) {
  int num1 = 0, num2 = 0;
  char *string = "497849";
  char *format = "%5i";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_8) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%05i";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_9) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%hi";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_10) {
  long num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%li";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

// %u
START_TEST(test_11) {
  int num1 = 0, num2 = 0;
  char *string = "69";
  char *format = "%u";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_12) {
  int num1 = 0, num2 = 0;
  char *string = "497849";
  char *format = "%5u";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_13) {
  int num1 = 0, num2 = 0;
  char *string = "-793875";
  char *format = "%05u";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_14) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%hu";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_15) {
  long num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%lu";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_150) {
  long num1 = 0, num2 = 0;
  unsigned int n3 = 0, n4 = 0;
  char *string = "-79 aaand : 111";
  char *format = "%*lu aaand : %u";
  ck_assert_int_eq(s21_sscanf(string, format, &num1, &n3),
                   sscanf(string, format, &num2, &n4));
  ck_assert_uint_eq(num1, num2);
  ck_assert_uint_eq(n3, n4);
}
END_TEST

START_TEST(test_151) {
  long num1 = 0, num2 = 0;
  unsigned int n3 = 0, n4 = 0;
  char *string = "-79 aaand : 111";
  char *format = "%lu aaand : NOO %u";
  ck_assert_int_eq(s21_sscanf(string, format, &num1, &n3),
                   sscanf(string, format, &num2, &n4));
  ck_assert_uint_eq(num1, num2);
  ck_assert_uint_eq(n3, n4);
}
END_TEST

// %o
START_TEST(test_16) {
  int num1 = 0, num2 = 0;
  char *string = "14731";
  char *format = "%o";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_17) {
  int num1 = 0, num2 = 0;
  char *string = "0";
  char *format = "%7o";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_18) {
  int num1 = 0, num2 = 0;
  char *string = "0";
  char *format = "%05o";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_19) {
  int num1 = 0, num2 = 0;
  char *string = "7968076";
  char *format = "%ho";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_20) {
  long num1 = 0, num2 = 0;
  char *string = "7798769";
  char *format = "%lo";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

// %x
START_TEST(test_21) {
  int num1 = 0, num2 = 0;
  char *string = "69";
  char *format = "%x";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_22) {
  int num1 = 0, num2 = 0;
  char *string = "497849";
  char *format = "%5x";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_23) {
  int num1 = 0, num2 = 0;
  char *string = "-793875";
  char *format = "%05x";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_24) {
  int num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%hx";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_25) {
  long num1 = 0, num2 = 0;
  char *string = "-79";
  char *format = "%lx";
  ck_assert_int_eq(s21_sscanf(string, format, &num1),
                   sscanf(string, format, &num2));
  ck_assert_int_eq(num1, num2);
}
END_TEST

// %c
START_TEST(test_26) {
  char c1 = '0', c2 = '0';
  char *string = "Y";
  char *format = "%c";
  ck_assert_int_eq(s21_sscanf(string, format, &c1),
                   sscanf(string, format, &c2));
  ck_assert(c1 == c2);
}
END_TEST

START_TEST(test_27) {
  char c1 = '0', c2 = '0';
  char *string = "w";
  char *format = "%0c";
  ck_assert_int_eq(s21_sscanf(string, format, &c1),
                   sscanf(string, format, &c2));
  ck_assert(c1 == c2);
}
END_TEST

START_TEST(test_28) {
  char c1 = '0', c2 = '0';
  char *format = "%16c";
  ck_assert_int_eq(s21_sscanf("H", format, &c1), sscanf("H", format, &c2));
  ck_assert(c1 == c2);
}
END_TEST

START_TEST(test_29) {
  char c1 = '0', c2 = '0';
  char *string = "?";
  char *format = "%c";
  ck_assert_int_eq(s21_sscanf(string, format, &c1),
                   sscanf(string, format, &c2));
  ck_assert(c1 == c2);
}
END_TEST

START_TEST(test_30) {
  wchar_t c1 = '0', c2 = '0';
  char *string = "寝たい";
  char *format = "%lc";
  ck_assert_int_eq(s21_sscanf(string, format, &c1),
                   sscanf(string, format, &c2));
  ck_assert(c1 == c2);
}
END_TEST

// %s
START_TEST(test_31) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  char *string = "Some text";
  char *format = "%s";
  ck_assert_int_eq(s21_sscanf(string, format, str1),
                   sscanf(string, format, str2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_32) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  char *string = "Something";
  char *format = "%5s";
  ck_assert_int_eq(s21_sscanf(string, format, str1),
                   sscanf(string, format, str2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_33) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  char *string = "Wonderful!";
  char *format = "%07s";
  ck_assert_int_eq(s21_sscanf(string, format, str1),
                   sscanf(string, format, str2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_34) {
  wchar_t str1[BUFF_SIZE] = {0}, str2[BUFF_SIZE] = {0};
  char *string = "寝たい";
  char *format = "%ls";
  ck_assert_int_eq(s21_sscanf(string, format, str1),
                   sscanf(string, format, str2));
  ck_assert(*str1 == *str2);
}
END_TEST

/*START_TEST(test_35) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE], str3[BUFF_SIZE], str4[BUFF_SIZE],
str5[BUFF_SIZE], str6[BUFF_SIZE]; char *string = "Let's check this !!!!"; char
*format = "%s %s %s"; ck_assert_int_eq(s21_sscanf(string, format, str1, str2,
str3), sscanf(string, format, str4, str5, str6)); ck_assert_str_eq(str1, str4);
  ck_assert_str_eq(str2, str5);
  ck_assert_str_eq(str3, str6);
}
END_TEST*/

// %f
START_TEST(test_36) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "562.2389";
  char *format = "%f";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_37) {
  double f1 = 0.0, f2 = 0.0;
  char *string = "9964.84673";
  char *format = "%lf";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_38) {
  long double f1 = 0.0, f2 = 0.0;
  char *string = "947623984632.947623984632";
  char *format = "%Lf";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_39) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "0";
  char *format = "%f";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_40) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "-68.98765430";
  char *format = "%5f";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

// %e
START_TEST(test_41) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "562.2389";
  char *format = "%e";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_42) {
  double f1 = 0.0, f2 = 0.0;
  char *string = "9964.84673";
  char *format = "%le";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_43) {
  long double f1 = 0.0, f2 = 0.0;
  char *string = "947623984632.947623984632";
  char *format = "%Le";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_44) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "0";
  char *format = "%e";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_45) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "-68.98765430";
  char *format = "%5e";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

// %g
START_TEST(test_46) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "562.2389";
  char *format = "%g";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_47) {
  double f1 = 0.0, f2 = 0.0;
  char *string = "9964.84673";
  char *format = "%lg";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_48) {
  long double f1 = 0.0, f2 = 0.0;
  char *string = "947623984632.947623984632";
  char *format = "%Lg";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_49) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "0";
  char *format = "%g";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

START_TEST(test_50) {
  float f1 = 0.0, f2 = 0.0;
  char *string = "-68.98765430";
  char *format = "%5g";
  ck_assert_int_eq(s21_sscanf(string, format, &f1),
                   sscanf(string, format, &f2));
  ck_assert(f1 == f2);
}
END_TEST

// %f mycahsze
START_TEST(test_51) {
  double n1 = 0, n2 = 0;
  char *string = "56.65";
  char *format = "%lf";
  ck_assert_int_eq(s21_sscanf(string, format, &n1),
                   sscanf(string, format, &n2));
  ck_assert_double_eq(n1, n2);
}
END_TEST

START_TEST(test_52) {
  long double n1 = 0, n2 = 0;
  char *string = "56.6000567567765757575";
  char *format = "%Lf";
  ck_assert_int_eq(s21_sscanf(string, format, &n1),
                   sscanf(string, format, &n2));
  ck_assert_ldouble_eq(n1, n2);
}
END_TEST

START_TEST(test_53) {
  float n1 = 0, n2 = 0;
  char *string = "56.65";
  char *format = "%*f";
  ck_assert_int_eq(s21_sscanf(string, format, &n1),
                   sscanf(string, format, &n2));
  ck_assert_float_eq(n1, n2);
}
END_TEST

START_TEST(test_54) {
  double n1 = 0, n2 = 0, n3 = 1, n4 = 1;
  char *string = "56.65 and -32.2";
  char *format = "%*lf and %lf";
  ck_assert_int_eq(s21_sscanf(string, format, &n1, &n3),
                   sscanf(string, format, &n2, &n4));
  ck_assert_double_eq(n1, n2);
  ck_assert_double_eq(n3, n4);
}
END_TEST

START_TEST(test_55) {
  double n1 = 0, n2 = 0;
  char *string = "\t -0.12345678";
  char *format = "%6lf";
  ck_assert_int_eq(s21_sscanf(string, format, &n1),
                   sscanf(string, format, &n2));
  ck_assert_double_eq(n1, n2);
}
END_TEST

// %p mycahsze
START_TEST(test_56) {
  char *p = "0";
  char *p1 = NULL;
  char *p2 = NULL;
  char string[BUFF_SIZE];
  sprintf(string, " %p ", p);
  char *format = "%p";
  ck_assert_int_eq(s21_sscanf(string, format, &p1),
                   sscanf(string, format, &p2));
  ck_assert_pstr_eq(p1, p2);
}
END_TEST

START_TEST(test_57) {
  char *p = "0";
  char *p1 = NULL;
  char *p2 = NULL;
  char string[BUFF_SIZE];
  sprintf(string, " %5p ", p);
  char *format = "%5p";
  ck_assert_int_eq(s21_sscanf(string, format, &p1),
                   sscanf(string, format, &p2));
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_58) {
  double p = 0.;
  double *p1 = NULL;
  double *p2 = NULL;
  char string[BUFF_SIZE];
  sprintf(string, " %p ", &p);
  char *format = "%p";
  ck_assert_int_eq(s21_sscanf(string, format, &p1),
                   sscanf(string, format, &p2));
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_59) {
  int p = 666;
  int ptr = 777;
  int *p1 = NULL;
  int *p2 = NULL;
  int *p3 = NULL;
  int *p4 = NULL;
  char string[BUFF_SIZE];
  sprintf(string, " %p %p", &p, &ptr);
  char *format = "%*p %p";
  ck_assert_int_eq(s21_sscanf(string, format, &p1, &p3),
                   sscanf(string, format, &p2, &p4));
  ck_assert_ptr_eq(p1, p2);
  ck_assert_ptr_eq(p3, p4);
}
END_TEST

// miscellaneous
START_TEST(test_60) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int i1 = 0, i2 = 0;
  int m1 = 1, m2 = 1;
  char c1 = '\0', c2 = '\0';
  int n1 = 0, n2 = 0;
  char *string = "Something; 0x43a; \t hello";
  char *format = "%5s; %*3i; %*n %*c %n";
  ck_assert_int_eq(s21_sscanf(string, format, str1, &i1, &m1, &c1, &n1),
                   sscanf(string, format, str2, &i2, &m2, &c2, &n2));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(m1, m2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(test_61) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int i1 = 0, i2 = 0;
  int m1 = 1, m2 = 1;
  char c1 = '\0', c2 = '\0';
  int n1 = 0, n2 = 0;
  char *string = "Something; 0x43a; \t hello";
  char *format = "%5s; %i; %ln %*c hello %n";
  ck_assert_int_eq(s21_sscanf(string, format, str1, &i1, &m1, &c1, &n1),
                   sscanf(string, format, str2, &i2, &m2, &c2, &n2));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(m1, m2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(test_62) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int i1 = 0, i2 = 0;
  int m1 = 1, m2 = 1;
  char c1 = '\0', c2 = '\0';
  int n1 = 0, n2 = 0;
  char *string = "Something: 0x43a \t hello";
  char *format = "%s: %i %hn %c \n %ln";
  ck_assert_int_eq(s21_sscanf(string, format, str1, &i1, &m1, &c1, &n1),
                   sscanf(string, format, str2, &i2, &m2, &c2, &n2));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(m1, m2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}

// START_TEST(test_63) {
//   char str1[BUFF_SIZE], str2[BUFF_SIZE];
//   int i1 = 0, i2 = 0;
//   int m1 = 1, m2 = 1;
//   char c1 = '\0', c2 = '\0';
//   int n1 = 0, n2 = 0;
//   char *string = "Something: 043 \t hello";
//   char *format = "%s: %i %hn %c \n  ello %ln";
//   ck_assert_int_eq(s21_sscanf(string, format, str1, &i1, &m1, &c1, &n1),
//   sscanf(string, format, str2, &i2, &m2, &c2, &n2)); ck_assert_str_eq(str1,
//   str2); ck_assert_int_eq(i1, i2); ck_assert_int_eq(m1, m2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(n1, n2);
// }

Suite *s21_sscanf_suite(void) {
  Suite *s;
  TCase *tc_core;

  // my_tests();

  s = suite_create("s21_sscanf");
  tc_core = tcase_create("Core");

  // %d
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  // %i
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  tcase_add_test(tc_core, test_9);
  tcase_add_test(tc_core, test_10);
  // %u
  tcase_add_test(tc_core, test_11);
  tcase_add_test(tc_core, test_12);
  tcase_add_test(tc_core, test_13);
  tcase_add_test(tc_core, test_14);
  tcase_add_test(tc_core, test_15);
  tcase_add_test(tc_core, test_150);
  tcase_add_test(tc_core, test_151);
  // %o
  tcase_add_test(tc_core, test_16);
  tcase_add_test(tc_core, test_17);
  tcase_add_test(tc_core, test_18);
  tcase_add_test(tc_core, test_19);
  tcase_add_test(tc_core, test_20);
  // %x
  tcase_add_test(tc_core, test_21);
  tcase_add_test(tc_core, test_22);
  tcase_add_test(tc_core, test_23);
  tcase_add_test(tc_core, test_24);
  tcase_add_test(tc_core, test_25);
  // %c
  tcase_add_test(tc_core, test_26);
  tcase_add_test(tc_core, test_27);
  tcase_add_test(tc_core, test_28);
  tcase_add_test(tc_core, test_29);
  tcase_add_test(tc_core, test_30);
  // %s
  tcase_add_test(tc_core, test_31);
  tcase_add_test(tc_core, test_32);
  tcase_add_test(tc_core, test_33);
  tcase_add_test(tc_core, test_34);
  //   tcase_add_test(tc_core, test_35);
  // %f
  tcase_add_test(tc_core, test_36);
  tcase_add_test(tc_core, test_37);
  tcase_add_test(tc_core, test_38);
  tcase_add_test(tc_core, test_39);
  tcase_add_test(tc_core, test_40);
  // %e
  tcase_add_test(tc_core, test_41);
  tcase_add_test(tc_core, test_42);
  tcase_add_test(tc_core, test_43);
  tcase_add_test(tc_core, test_44);
  tcase_add_test(tc_core, test_45);
  // %g
  tcase_add_test(tc_core, test_46);
  tcase_add_test(tc_core, test_47);
  tcase_add_test(tc_core, test_48);
  tcase_add_test(tc_core, test_49);
  tcase_add_test(tc_core, test_50);
  // %f mycahzse
  tcase_add_test(tc_core, test_51);
  tcase_add_test(tc_core, test_52);
  tcase_add_test(tc_core, test_53);
  tcase_add_test(tc_core, test_54);
  tcase_add_test(tc_core, test_55);
  // %p mycahzse
  tcase_add_test(tc_core, test_56);
  tcase_add_test(tc_core, test_57);
  tcase_add_test(tc_core, test_58);
  tcase_add_test(tc_core, test_59);
  // miscellaneous
  tcase_add_test(tc_core, test_60);
  tcase_add_test(tc_core, test_61);
  tcase_add_test(tc_core, test_62);
  // tcase_add_test(tc_core, test_63);

  suite_add_tcase(s, tc_core);

  return s;
}
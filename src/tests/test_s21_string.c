#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "tests.h"

// keenanbu
START_TEST(test_s21_memcpy) {
  char test_string1[35] = "Hey! It's just some test string.\0";
  char test_string1_2[35] = "Hey! It's just some test string.\0";
  char test_string2[10] = "Wha-a-at?";
  char test_string3[55] =
      "Some more test string 1234555\nand two more fives: 55.";
  char test_string3_2[55] =
      "Some more test string 1234555\nand two more fives: 55.";
  char test_string4[1] = "\0";
  char test_string5[40] = "123 lol kek cheburek!\0And smth more.";
  ck_assert_str_eq(s21_memcpy(test_string1, test_string2, 9),
                   memcpy(test_string1_2, test_string2, 9));
  ck_assert_str_eq(s21_memcpy(test_string1, test_string4, 1),
                   memcpy(test_string1_2, test_string4, 1));
  ck_assert_str_eq(s21_memcpy(test_string1, test_string5, 35),
                   memcpy(test_string1_2, test_string5, 35));
  ck_assert_str_eq(s21_memcpy(test_string1, test_string2, 10),
                   memcpy(test_string1_2, test_string2, 10));
  ck_assert_str_eq(s21_memcpy(test_string1, test_string3, 0),
                   memcpy(test_string1_2, test_string3, 0));
  ck_assert_str_eq(s21_memcpy(test_string3, test_string5, 1),
                   memcpy(test_string3_2, test_string5, 1));
}
END_TEST

START_TEST(test_s21_memset) {
  char test_string1[35] = "Hey! It's just some test string.\0";
  char test_string1_2[35] = "Hey! It's just some test string.\0";
  char test_string2[40] = "123 lol kek cheburek!\0And smth more.";
  char test_string2_2[40] = "123 lol kek cheburek!\0And smth more.";
  char test_string3[55] =
      "Some more test string 1234555\nand two more fives: 55.";
  char test_string3_2[55] =
      "Some more test string 1234555\nand two more fives: 55.";
  ck_assert_str_eq(s21_memset(test_string1, '\0', 1),
                   memset(test_string1_2, '\0', 1));
  ck_assert_str_eq(s21_memset(test_string1, '5', 1),
                   memset(test_string1_2, '5', 1));
  ck_assert_str_eq(s21_memset(test_string1, '5', 30),
                   memset(test_string1_2, '5', 30));
  ck_assert_str_eq(s21_memset(test_string2, 'o', 12),
                   memset(test_string2_2, 'o', 12));
  ck_assert_str_eq(s21_memset(test_string2, '\0', 11),
                   memset(test_string2_2, '\0', 11));
  ck_assert_str_eq(s21_memset(test_string3, '?', 33),
                   memset(test_string3_2, '?', 33));
  ck_assert_str_eq(s21_memset(test_string3, '.', 10),
                   memset(test_string3_2, '.', 10));
}
END_TEST

START_TEST(test_s21_strchr) {
  const char *test_string1 = "Hey! It's just some test string.\0";
  const char *test_string2 = "\0";
  const char *test_string3 =
      "Some more test string 1234555\nand two more fives: 55.";
  ck_assert_ptr_eq(s21_strchr(test_string1, C1), strchr(test_string1, C1));
  ck_assert_ptr_eq(s21_strchr(test_string1, C2), strchr(test_string1, C2));
  ck_assert_ptr_eq(s21_strchr(test_string2, C2), strchr(test_string2, C2));
  ck_assert_ptr_eq(s21_strchr(test_string1, C3), strchr(test_string1, C3));
  ck_assert_ptr_eq(s21_strchr(test_string1, C4), strchr(test_string1, C4));
  ck_assert_ptr_eq(s21_strchr(test_string1, C5), strchr(test_string1, C5));
  ck_assert_ptr_eq(s21_strchr(test_string3, C5), strchr(test_string3, C5));
}
END_TEST

START_TEST(test_s21_strrchr) {
  const char *test_string1 = "Hey! It's just some test string.\0";
  const char *test_string2 = "\0";
  const char *test_string3 =
      "Some more test string 1234555\nand two more fives: 55.";
  ck_assert_ptr_eq(s21_strrchr(test_string1, C1), strrchr(test_string1, C1));
  ck_assert_ptr_eq(s21_strrchr(test_string1, C2), strrchr(test_string1, C2));
  ck_assert_ptr_eq(s21_strrchr(test_string2, C2), strrchr(test_string2, C2));
  ck_assert_ptr_eq(s21_strrchr(test_string1, C3), strrchr(test_string1, C3));
  ck_assert_ptr_eq(s21_strrchr(test_string1, C4), strrchr(test_string1, C4));
  ck_assert_ptr_eq(s21_strrchr(test_string1, C5), strrchr(test_string1, C5));
  ck_assert_ptr_eq(s21_strrchr(test_string3, C5), strrchr(test_string3, C5));
}
END_TEST

START_TEST(test_s21_memchr) {
  char str[] = "Hi there!";
  int c = 'r';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
  c = '!';
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
  c = 'w';
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
  char str1[] = "";
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
  char str2[] = "Some more text to test this function.\0";
  n = s21_strlen(str2);
  c = '\0';
  ck_assert_ptr_eq(memchr(str2, c, n), s21_memchr(str2, c, n));
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
  char str3[] =
      "This is a very long string and I have no idea why "
      "I'm writing all this stuff... "
      "So let's talk about this function. What does it actually do? "
      "The memchr() function scans the initial n bytes of the memory area "
      "pointed to by s for the first instance of c. Both c and the bytes of "
      "the memory area pointed to by s are interpreted as unsigned char.\0";
  n = s21_strlen(str3);
  ck_assert_ptr_eq(memchr(str3, c, n), s21_memchr(str3, c, n));
  c = ')';
  ck_assert_ptr_eq(memchr(str3, c, n), s21_memchr(str3, c, n));
  c = '9';
  ck_assert_ptr_eq(memchr(str3, c, n), s21_memchr(str3, c, n));
  char str4[] = "9876543210";
  n = s21_strlen(str4);
  ck_assert_ptr_eq(memchr(str4, c, n), s21_memchr(str4, c, n));
  c = '.';
  ck_assert_ptr_eq(memchr(str4, c, n), s21_memchr(str4, c, n));
}
END_TEST

START_TEST(test_s21_strcat) {
  char dest[50] = "Hi there! ";
  char src[] = "What's up?";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
  char src1[] = "\0";
  ck_assert_str_eq(strcat(dest, src1), s21_strcat(dest, src1));
  char dest1[50] = "\0";
  ck_assert_str_eq(strcat(dest1, src1), s21_strcat(dest1, src1));
  ck_assert_str_eq(strcat(dest1, src), s21_strcat(dest1, src));
  char dest2[200] =
      "Let's see what happens if we add the null terminator "
      "in the middle of this string. \0 And then add something.";
  char src2[] = "And then add something else.";
  ck_assert_str_eq(strcat(dest2, src2), s21_strcat(dest2, src2));
  char dest3[20] = "98765";
  char src3[] = "43210";
  ck_assert_str_eq(strcat(dest3, src3), s21_strcat(dest3, src3));
  char src4[] = "\043210";
  ck_assert_str_eq(strcat(dest3, src4), s21_strcat(dest3, src4));
}
END_TEST

START_TEST(test_s21_strncat) {
  char dest[50] = "Hi there! ";
  char src[] = "What's up?";
  ck_assert_str_eq(strncat(dest, src, 10), s21_strncat(dest, src, 10));
  char src1[] = "\0";
  ck_assert_str_eq(strncat(dest, src1, 1), s21_strncat(dest, src1, 1));
  char dest1[50] = "\0";
  ck_assert_str_eq(strncat(dest1, src1, 1), s21_strncat(dest1, src1, 1));
  ck_assert_str_eq(strncat(dest1, src, 4), s21_strncat(dest1, src, 4));
  char dest2[200] =
      "Let's see what happens if we add the null terminator "
      "in the middle of this string. \0 And then add something.";
  char src2[] = "And then add something else.";
  ck_assert_str_eq(strncat(dest2, src2, 28), s21_strncat(dest2, src2, 28));
  char dest3[20] = "98765";
  char src3[] = "43210";
  ck_assert_str_eq(strncat(dest3, src3, 5), s21_strncat(dest3, src3, 5));
  char src4[] = "\043210";
  ck_assert_str_eq(strncat(dest3, src4, 6), s21_strncat(dest3, src4, 6));
}
END_TEST

// dawaylau
START_TEST(test_strcpy) {
  char str[7];
  char *temp = "abcdef";
  ck_assert_str_eq(s21_strcpy(str, "123456\0"), strcpy(str, "123456\0"));
  ck_assert_str_eq(s21_strcpy(str, temp), strcpy(str, temp));
  ck_assert_str_eq(s21_strcpy(str, "123"), strcpy(str, "123"));
  ck_assert_str_eq(s21_strcpy(str, "\0"), strcpy(str, "\0"));
}
END_TEST

START_TEST(test_strncpy) {
  for (int i = 0; i < 10; i++) {
    char *str1 = (char *)calloc(10, sizeof(char));
    char *str2 = (char *)calloc(10, sizeof(char));
    ck_assert_str_eq(s21_strncpy(str1, "1234567890\0", i),
                     s21_strncpy(str2, "1234567890\0", i));
    free(str1);
    free(str2);
  }
}
END_TEST

START_TEST(test_strcspn) {
  ck_assert_int_eq(s21_strcspn("abcdefg", "cd"), strcspn("abcdefg", "cd"));
  ck_assert_int_eq(s21_strcspn("abcdefg", "12"), strcspn("abcdefg", "12"));
  ck_assert_int_eq(s21_strcspn("abcdefg", "abcdefg"),
                   strcspn("abcdefg", "abcdefg"));
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

START_TEST(test_strstr) {
  ck_assert_str_eq(s21_strstr("1234567890", "67"), strstr("1234567890", "67"));
  ck_assert_ptr_eq(s21_strstr("1234567890", "ab"), strstr("1234567890", "ab"));
  ck_assert_str_eq(s21_strstr("1234567890", "1234567890"),
                   strstr("1234567890", "1234567890"));
  ck_assert_str_eq(s21_strstr("1234567890", ""), strstr("1234567890", ""));
  ck_assert_str_eq(s21_strstr("", ""), strstr("", ""));
}
END_TEST

START_TEST(test_to_upper) {
  char *str2 = s21_to_upper("abcdefj");
  ck_assert_str_eq(str2, "ABCDEFJ");
  if (str2) free(str2);
  char *str3 = s21_to_upper("ABCDEFJ");
  ck_assert_str_eq(str3, "ABCDEFJ");
  if (str3) free(str3);
  char *str4 = s21_to_upper("1234567890");
  ck_assert_str_eq(str4, "1234567890");
  if (str4) free(str4);
  char *str5 = s21_to_upper("Ab1cD23e");
  ck_assert_str_eq(str5, "AB1CD23E");
  if (str5) free(str5);
}
END_TEST

START_TEST(test_to_lower) {
  char *str1 = s21_to_lower("ABCDEFJ");
  ck_assert_str_eq(str1, "abcdefj");
  if (str1) free(str1);
  char *str2 = s21_to_lower("abcdefj");
  ck_assert_str_eq(str2, "abcdefj");
  if (str2) free(str2);
  char *str3 = s21_to_lower("1234567890");
  ck_assert_str_eq(str3, "1234567890");
  if (str3) free(str3);
  char *str4 = s21_to_lower("Ab1cD23e");
  ck_assert_str_eq(str4, "ab1cd23e");
  if (str4) free(str4);
}
END_TEST

// TESTS TRIM & INSERT

START_TEST(test_insert) {
  // printf("\ninsert function:\n");

  // 3 position
  char *str1 = s21_insert("0123456", "abc", 3);
  ck_assert_str_eq(str1, "012abc3456");
  if (str1) free(str1);
  // 0 position
  char *str2 = s21_insert("0123456", "abc", 0);
  ck_assert_str_eq(str2, "abc0123456");
  if (str2) free(str2);
  // last position
  char *str3 = s21_insert("0123456", "abc", 6);
  ck_assert_str_eq(str3, "012345abc6");
  if (str3) free(str3);
  // nonexist position
  char *str4 = s21_insert("0123456", "abc", 10);
  ck_assert_ptr_eq(str4, NULL);
  if (str4) free(str4);
  // empty string
  char *str5 = s21_insert("", "abc", 1);
  ck_assert_ptr_eq(str5, NULL);
  if (str5) free(str5);
  // negative index
  char *str6 = s21_insert("0123456", "abc", -545548);
  ck_assert_ptr_eq(str6, NULL);
  if (str6) free(str6);
  // empty string
  char *str7 = s21_insert("0123456", "\0", 3);
  ck_assert_ptr_eq(str7, NULL);
  if (str7) free(str7);
}
END_TEST

/*
Возвращает новую строку, в которой удаляются все начальные и конечные вхождения
набора заданных символов (trim_chars) из данной строки (src). В случае
какой-либо ошибки следует вернуть значение NULL
*/

START_TEST(test_trim) {
  // printf("\ntrim function:\n");

  // at the beginning
  char *str1 = s21_trim("abc0123456", "abc");
  ck_assert_str_eq(str1, "0123456");
  if (str1) free(str1);
  // at the end
  char *str2 = s21_trim("0123456abc", "abc");
  ck_assert_str_eq(str2, "0123456");
  if (str2) free(str2);
  // beginning and end
  char *str3 = s21_trim("abc0123456abc", "abc");
  ck_assert_str_eq(str3, "0123456");
  if (str3) free(str3);
  // beginning, end and middle
  char *str4 = s21_trim("abc0123abc456abc", "abc");
  ck_assert_str_eq(str4, "0123abc456");
  if (str4) free(str4);
  // beginning and end with a shift
  char *str5 = s21_trim("0abc12345abc6", "abc");
  ck_assert_str_eq(str5, "0abc12345abc6");
  if (str5) free(str5);
  // one char
  char *str6 = s21_trim("***012345***", "*");
  ck_assert_str_eq(str6, "012345");
  if (str6) free(str6);
  // two chars
  char *str7 = s21_trim("* **012345 * * *", "* ");
  ck_assert_str_eq(str7, "012345");
  if (str7) free(str7);
  // empty trim_chars
  char *str8 = s21_trim("  012345\t\n", "");
  ck_assert_str_eq(str8, "012345");
  if (str8) free(str8);
  // empty src
  char *str9 = s21_trim("", "122");
  ck_assert_ptr_eq(str9, NULL);
  if (str9) free(str9);
}
END_TEST

// sharikac
START_TEST(test_memcmp) {
  // testing equal strings
  char *t11 = "this is string";
  char *t12 = "this is string";
  for (int i = 0; i < 20; i++)
    ck_assert_int_eq(memcmp(t11, t12, i), s21_memcmp(t11, t12, i));

  // testing empty string and \0 character
  char *t21 = "\0";
  char *t22 = "";
  ck_assert_int_eq(memcmp(t21, t22, 1), s21_memcmp(t21, t22, 1));

  // testing different size strings
  char *t31 = "0124821213";
  char *t32 = "01248";
  ck_assert_int_eq(memcmp(t31, t32, 4), s21_memcmp(t31, t32, 4));
  ck_assert_int_eq(memcmp(t31, t32, 5), s21_memcmp(t31, t32, 5));

  // TEST THIS ON MAC
  // testing different strings
  // char* t41 = "01\02482";
  // char* t42 = "013\0481";
  // ck_assert_int_eq(memcmp(t41, t42, 6), s21_memcmp(t41, t42, 6));
}
END_TEST

START_TEST(test_memmove) {
  char *a = "0123456789";
  // scr > dest
  for (int i = 0; i < 10; i++) {
    char *dest11 = (char *)calloc(10, sizeof(char));
    char *dest12 = (char *)calloc(10, sizeof(char));
    for (int i = 0; i < 10; i++) {
      dest11[i] = a[i];
      dest12[i] = a[i];
    }
    char *src11 = dest11 + 3;
    char *src12 = dest12 + 3;
    ck_assert_str_eq(s21_memmove(dest11, src11, i),
                     s21_memmove(dest12, src12, i));
    free(dest11);
    free(dest12);
  }
  // dest > src
  for (int i = 0; i < 10; i++) {
    char *src21 = (char *)calloc(10, sizeof(char));
    char *src22 = (char *)calloc(10, sizeof(char));
    for (int i = 0; i < 10; i++) {
      src21[i] = a[i];
      src22[i] = a[i];
    }
    char *dest21 = src21 + 3;
    char *dest22 = src22 + 3;
    ck_assert_str_eq(s21_memmove(dest21, src21, i),
                     s21_memmove(dest22, src22, i));
    free(src21);
    free(src22);
  }
  // dest == src
  for (int i = 0; i < 10; i++) {
    char *src31 = (char *)calloc(10, sizeof(char));
    char *src32 = (char *)calloc(10, sizeof(char));
    for (int i = 0; i < 10; i++) {
      src31[i] = a[i];
      src32[i] = a[i];
    }
    char *dest31 = src31;
    char *dest32 = src32;
    ck_assert_str_eq(s21_memmove(dest31, src31, i),
                     s21_memmove(dest32, src32, i));
    free(src31);
    free(src32);
  }
  // dest != src
  for (int i = 0; i < 12; i++) {
    char src41[] = "stringstring";
    char src42[] = "stringstring";
    char dest41[] = "not a string";
    char dest42[] = "not a string";
    ck_assert_str_eq(s21_memmove(dest41, src41, i),
                     s21_memmove(dest42, src42, i));
  }
}
END_TEST

START_TEST(test_strerror) {
  // TEST THIS ON MAC
  for (int i = -200; i < 300; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_strtok) {
  char str1[] =
      ".........string stringstring str   s, string string ,.str string str   ";
  char str2[] =
      ".........string stringstring str   s, string string ,.str string str   ";
  char *pch1 = strtok(str1, " ,.");
  char *pch2 = s21_strtok(str2, " ,.");
  ck_assert_str_eq(pch1, pch2);
  ck_assert_str_eq(str1, str2);
  for (int i = 0; i < 8; i++) {
    pch1 = strtok(NULL, " ,.");
    pch2 = s21_strtok(s21_NULL, " ,.");
    ck_assert_str_eq(pch1, pch2);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

// mycahsze TESTS
START_TEST(test_strspn) {
  char *s1 = "hello_world";
  char *s2 = "";
  char *s3 = "H";
  char *s4 = "123Oleg2lego";
  char *s5 = "123Oleg!";
  ck_assert_int_eq(s21_strspn(s1, "heol"), strspn(s1, "heol"));
  ck_assert_int_eq(s21_strspn(s2, ""), strspn(s2, ""));
  ck_assert_int_eq(s21_strspn(s3, "H"), strspn(s3, "H"));
  ck_assert_int_eq(s21_strspn(s4, s5), strspn(s4, s5));
  ck_assert_int_eq(s21_strspn(s4, "1Og"), strspn(s4, "1Og"));
  ck_assert_int_eq(s21_strspn(s1, "abc"), strspn(s1, "abc"));
}
END_TEST

START_TEST(test_strpbrk) {
  char *s1 = "hello_world";
  char *s2 = "hello\nworld!";
  char *s3 = "H";
  char *s4 = "123Oleg";
  char *s5 = "123Oleg!";
  ck_assert_ptr_eq(s21_strpbrk(s1, "hed"), strpbrk(s1, "hed"));
  ck_assert_ptr_eq(s21_strpbrk(s3, "H"), strpbrk(s3, "H"));
  ck_assert_ptr_eq(s21_strpbrk(s4, s5), strpbrk(s4, s5));
  ck_assert_ptr_eq(s21_strpbrk(s4, "1Og"), strpbrk(s4, "1Og"));
  ck_assert_ptr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
  ck_assert_ptr_eq(s21_strpbrk(s1, s5), strpbrk(s1, s5));
  ck_assert_ptr_eq(s21_strpbrk(s5, "!"), strpbrk(s5, "!"));
}
END_TEST

START_TEST(test_strcmp) {
  char *s1 = "hello_world";
  char *s2 = "hello\nworld!";
  char *s3 = "H";
  char *s4 = "123Oleg";
  char *s5 = "123Ole!";
  ck_assert_int_eq(s21_strcmp(s1, "hello_world"), strcmp(s1, "hello_world"));
  ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
  ck_assert_int_eq(s21_strcmp(s3, "h"), strcmp(s3, "h"));
  ck_assert_int_eq(s21_strcmp(s4, s5), strcmp(s4, s5));
  ck_assert_int_eq(s21_strcmp(s5, ""), strcmp(s5, ""));
}
END_TEST

START_TEST(test_strncmp) {
  char *s1 = "hello_world";
  char *s2 = "hello\nworld!";
  char *s3 = "H";
  char *s4 = "123Oleg";
  char *s5 = "123Ole!";
  ck_assert_int_eq(3, 3);
  ck_assert_int_eq(s21_strncmp(s1, "hello_world", 11),
                   strncmp(s1, "hello_world", 11));
  ck_assert_int_eq(s21_strncmp(s1, s2, 20), strncmp(s1, s2, 20));
  ck_assert_int_eq(s21_strncmp(s3, "H", 2), strncmp(s3, "H", 2));
  ck_assert_int_eq(s21_strncmp(s3, "H", 1), strncmp(s3, "H", 1));
  ck_assert_int_eq(s21_strncmp(s3, "H", 0), strncmp(s3, "H", 0));
  ck_assert_int_eq(s21_strncmp(s4, s5, 20), strncmp(s4, s5, 20));
  ck_assert_int_eq(s21_strncmp(s4, "123Ole!", 7), strncmp(s4, "123Ole!", 7));
  ck_assert_int_eq(s21_strncmp(s4, "123Ole!", 6), strncmp(s4, "123Ole!", 6));
  ck_assert_int_eq(s21_strncmp(s4, "123O", 4), strncmp(s4, "123O", 4));
  ck_assert_int_eq(s21_strncmp(s4, "123O", 5), strncmp(s4, "123O", 5));
  ck_assert_int_eq(s21_strncmp(s4, "123O", 3), strncmp(s4, "123O", 3));
}
END_TEST  // mycahsze END TESTS

    Suite *
    s21_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_string");
  tc_core = tcase_create("Core");

  // keenanbu
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_strcat);
  tcase_add_test(tc_core, test_s21_strncat);
  // dawaylau
  tcase_add_test(tc_core, test_strcpy);
  tcase_add_test(tc_core, test_strncpy);
  tcase_add_test(tc_core, test_strcspn);
  tcase_add_test(tc_core, test_strstr);
  tcase_add_test(tc_core, test_to_upper);
  tcase_add_test(tc_core, test_to_lower);
  tcase_add_test(tc_core, test_insert);
  tcase_add_test(tc_core, test_trim);
  // sharikac
  tcase_add_test(tc_core, test_memcmp);
  tcase_add_test(tc_core, test_memmove);
  tcase_add_test(tc_core, test_strerror);
  tcase_add_test(tc_core, test_strtok);
  // mycahsze
  tcase_add_test(tc_core, test_strspn);
  tcase_add_test(tc_core, test_strpbrk);
  tcase_add_test(tc_core, test_strcmp);
  tcase_add_test(tc_core, test_strncmp);
  suite_add_tcase(s, tc_core);

  return s;
}

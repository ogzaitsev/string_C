#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>

#define BUFF_SIZE 512
#define C1 'j'
#define C2 'w'
#define C3 't'
#define C4 'g'
#define C5 '5'

Suite *s21_string_suite(void);
Suite *s21_sprintf_suite(void);
Suite *s21_sscanf_suite(void);
void my_tests();

#endif
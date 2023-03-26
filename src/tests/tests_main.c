#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_sscanf.h"
#include "../s21_string.h"
#include "tests.h"

int main() {
  // setlocale(LC_NUMERIC, NULL);
  // localeconv()->decimal_point;
  setlocale(LC_NUMERIC, "C");
  setlocale(LC_ALL, "en_US.utf8");
  int no_failed = 0;
  Suite *suites[] = {s21_string_suite(), s21_sprintf_suite(),
                     s21_sscanf_suite(), NULL};

  for (Suite **pS = suites; *pS != NULL; pS++) {
    SRunner *sr = srunner_create(*pS);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

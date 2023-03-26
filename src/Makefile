CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
TFLAGS=-lcheck -lm -lpthread
CGFLAGS=-fprofile-arcs -ftest-coverage --coverage -O0
LIBDIR=-L.

all: s21_string.a s21_tests test gcov_report

s21_string.a: *.c s21_string.h s21_strerror.h s21_sprintf.h
	$(CC) $(CFLAGS) -c *.c
	ar -rcs s21_string.a *.o s21_string.h s21_strerror.h s21_sprintf.h

s21_tests: clean
	$(CC) $(CFLAGS) -c $(CGFLAGS) *.c
	ar -rcs libs21_string.a *.o s21_string.h s21_strerror.h s21_sprintf.h
	$(CC) $(CFLAGS) ./tests/tests.h ./tests/*.c $(LIBDIR) -ls21_string -o ./tests/s21_tests $(TFLAGS) $(CGFLAGS)

style_fix:
	clang-format --style=Google -i *.c *.h
	clang-format --style=Google -i tests/*.c tests/*.h

style_check:
	clang-format --style=Google -n *.c *.h
	clang-format --style=Google -n tests/*.c tests/*.h

memory_leaks_check:
	# CK_FORK=no valgrind --leak-check=full tests/s21_tests text
	CK_FORK=no leaks -atExit -- ./tests/s21_tests

test:
	./tests/s21_tests

gcov_report:
	gcov s21*.c
	lcov -t . -o ./report/report.info -c -d .
	genhtml -o report ./report/report.info
	open ./report/index.html

clean:
	rm -rf *.o *.a ./tests/s21_tests ./tests/coverage_report.* ./tests/*.gc* coverage.* *.gcno *.gcda *gcov report/*

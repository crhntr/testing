# testing.h

I wrote this library to help in testing my operating system class (COMP352)
labs and projects. "testing.h" is about as bare bones as you can get but I found
it useful and thought others might as well.

## Example
```c
// this is an example file for "testing.c"
// create something like this in the same dir as your
// project/lab
// in your Makefile you can put something like this
//
//    testv:
//        @gcc testing/testing.a where_abs_is.c test.c -o test.out
//        ./disk_t.out -v
//
//    test:
//        @gcc testing/testing.a where_abs_is.c test.c -o test.out
//        ./disk_t.out
//
#include "testing/testing.h"
// OR #include "../testing/testing.h"

void test_math(testing_t* t);
void test_abs(testing_t* t);

int main(int argc, char *argv[]) {
  testing_t *t = test_new_test_session(argc, argv);

  test_math(t);
  test_abs(t);

  return test_session_done(t);
}

void test_math(testing_t* t) {
  test(t, 4, 2+2, "math broke");
}

void test_abs(testing_t* t) {
  test_table_start(t);
  for (int i= 0; i< 100; i++, test_row_increment(t)) {
    test(t, 2, abs(-2), "abs should take absolute value of a number");
  }
  test_table_end(t);
}
```

## header file
```c
#ifndef TESTING_T
#define TESTING_T
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// testing_t must be intialized using
// the test_new_test_session function
typedef struct {
  // ...
} testing_t;

// test_new_test_session should be used to start a testing session
testing_t* test_new_test_session(int argc, char *argv[]);

// test_session_done should be called at the end of main to report
// the results of testing, returning the result from main is optional
// see example in readme
int test_session_done(testing_t* t);

// test should be used to test expectaions
void test(testing_t *t, int testValue, int shouldBe, char* failmMsg);

// test_table_start should be called before starting to test
// a logical group or table of tests
void test_table_start(testing_t* t);

// test_table_end should be called after completeing a logical group or
// table of tests
void test_table_end(testing_t* t);

// test_row_increment should be called at the end of a test row
void test_row_increment(testing_t* t);
#endif
```

# testing.h

I wrote this library to help in testing my operating system class (COMP352)
labs and projects. "testing.h" is about as bare bones as you can get but I found
it useful and thought others might as well.

See test.c for an example using this library.
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

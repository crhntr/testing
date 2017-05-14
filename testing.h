// Project: testing_t
// By:      Christopher Hunter
// Contact: [github|twitter].com/crhntr
// Created: 2017-05-13
//
#ifndef TESTING_T
#define TESTING_T
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
  int testIndex;
  int testFails;
  int tableIndex;
  int tableFails;
  int rowIndex;
  int rowFails;
  int verbose;
} testing_t;

void test(testing_t *t, int testValue, int shouldBe, char* failmMsg);

testing_t* test_new_test_session(int argc, char *argv[]);
int test_session_done(testing_t* t);

void test_table_start(testing_t* t);
void test_table_end(testing_t* t);
void test_row_increment(testing_t* t);
#endif

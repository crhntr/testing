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

#define testFunc(n) if(t->verbose){printf ("\n############################################# \rrunning test: " #n "\n\n");} t->testCount++; n(t);

// testing_t should be initalized using
// the test_new_test_session function
typedef struct {
  int testIndex;
  int testFails;
  int tableIndex;
  int tableFails;
  int rowIndex;
  int rowFails;
  int verbose;
  int testCount;
} testing_t;

// test_new_test_session should be used to start a testing session
testing_t* test_new_test_session(int argc, char *argv[]);

// test_session_done should be called at the end of main to report
// the results of testing, returning the result from main is optional
// see example in readme
int test_session_done(testing_t* t);

// test should be used to test expectaions it returns 0 if testValue == shouldBe
// it returns the result of testValue != shouldBe
int test(testing_t *t, int testValue, int shouldBe, char* failmMsg);

// test_table_start should be called before starting to test
// a logical group or table of tests
void test_table_start(testing_t* t);

// test_table_end should be called after completeing a logical group or
// table of tests
void test_table_end(testing_t* t);

// test_row_increment should be called at the end of a test row
void test_row_increment(testing_t* t);

// test_log logs msg if verbose flag set
void test_log(testing_t* t, char* logMsg);
#endif

// Project: testing_t
// By:      Christopher Hunter
// Contact: [github|twitter].com/crhntr
// Created: 2017-05-13
//
#include "testing.h"

void dbg(testing_t *t) {
  printf("{.testIndex = %d, .testFails = %d, .tableIndex = %d, .tableFails = %d, .rowIndex = %d, .rowFails = %d, .verbose = %d}\n",
  t->testIndex,
  t->testFails,
  t->tableIndex,
  t->tableFails,
  t->rowIndex,
  t->rowFails,
  t->verbose);
}

testing_t* test_new_test_session(int argc, char *argv[]) {
  int verbose = 0;
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
      printf("starting tests\n\n");
      verbose = 1;
    }
  }
  testing_t *t = (testing_t*) malloc(sizeof(testing_t));
  t->testIndex = 0;
  t->testFails = 0;
  t->tableIndex = -1;
  t->tableFails = 0;
  t->rowIndex = 0;
  t->rowFails = 0;
  t->verbose = verbose;
  // printf("\n\n\n\n\n\ntesting_t* test_new_test_session(int argc, char *argv[]) \n"); dbg(t);

  return t;
}

int test_session_done(testing_t* t) {
  // printf("\n\n\n\n\n\nint test_session_done(testing_t* t) \n"); dbg(t);
  int failCount = t->testFails;
  free(t);

  if (failCount > 0) {
    printf("\n%d tests failed\n", failCount);
    return 1;
  }
  return 0;
}

void test(testing_t *t, int expected, int got, char* failmMsg) {
  // printf("\n\n\n\n\n\nvoid test(testing_t *t, int expected, int got, char* failmMsg) \n"); dbg(t);
  if (t->tableIndex >= 0) {
    if (expected != got) {
      t->rowFails++;
      if (t->verbose) {
        printf("-->");
        if(t->tableIndex == 0) {
          printf(" [test#:%3d]", t->testIndex);
        } else {
          printf("            ");
        }
        if (t->rowIndex == 0) {
          printf("[row#:%3d]", t->rowIndex);
        } else {
          printf("          ");
        }
        printf(" exp:%-3d got:%-3d", expected, got);
        printf("\"%s\"\n", failmMsg);
      }
    }
  } else {
    t->testIndex++;
    t->rowIndex++;
    if (expected != got) {
      t->testFails++;
      if (t->verbose) {
        printf("--> [test#:%3d] ", t->testIndex);
        printf(" exp:%-3d got:%-3d", expected, got);
        printf("\"%s\"\n", failmMsg);
      }
    } else {
      if (t->verbose) {
        printf("--> [test#:%3d] OK\n", t->testIndex);
      }
    }
  }
}

void test_row_increment(testing_t* t) {
  // printf("\n\n\n\n\n\nvoid test_row_increment(testing_t* t) \n"); dbg(t);
  if (t->rowFails > 0) {
    t->tableFails++;
  } else {
    if (t->verbose) {
      printf("-->");
      if(t->tableIndex == 0) {
        printf(" [test#:%3d]", t->testIndex);
      } else {
        printf("            ");
      }
      printf("[row#:%3d] OK\n", t->rowIndex);
    }
  }
  t->tableIndex++;
  t->rowIndex++;
  t->rowFails = 0;
}

void test_table_start(testing_t* t) {
  // printf("\n\n\n\n\n\nvoid test_table_start(testing_t* t) \n"); dbg(t);
  t->tableIndex = 0;
  t->tableFails = 0;
  t->rowIndex = 0;
  t->rowFails = 0;
}

void test_table_end(testing_t* t) {
  // printf("\n\n\n\n\n\nvoid test_table_end(testing_t* t) \n"); dbg(t);
  if (t->tableFails >= 0) {
    t->testFails++;
  } else {
    if (t->verbose) {
      t->testIndex++;
      printf("--> [test#:%3d] OK\n", t->testIndex);
    }
  }
  t->tableIndex = -1;
  t->tableFails = 0;
  t->rowIndex = 0;
  t->rowFails = 0;
}

void test_log(testing_t* t, char* logMsg) {
  if (t->verbose) {
    printf("=> \"%s\"\n", logMsg);
  }
}

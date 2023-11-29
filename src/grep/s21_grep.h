#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "s21_grep: %s: No such file or directory\n"

#define BUFFER 10000

typedef struct {
  int e_option;
  int i_option;
  int v_option;
  int l_option;
  int n_option;
  int c_option;
  char str_patterns[BUFFER];
} Options;

int ParseFlags(int argc, char* argv[], Options* flag);

FILE* PrintFile(FILE* file, Options* flag, char* argv);

void OpenFile(int argc, char* argv[], Options* flag);
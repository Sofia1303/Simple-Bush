#include <getopt.h>
#include <stdio.h>

#define ERROR_01 "s21_cat: %s: No such file or directory\n"

static struct option long_option[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
};

typedef struct {
  int b_option;
  int E_option;
  int n_option;
  int s_option;
  int T_option;
  int v_option;
  int new_line;
} Options;

int ParseFlags(int argc, char* argv[], Options* flag);

FILE* PrintFile(FILE* file, Options* flag);

void OpenFile(int argc, char* argv[], Options* flag);

unsigned char vOption(unsigned char c);
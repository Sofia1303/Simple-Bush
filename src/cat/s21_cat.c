#include "s21_cat.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    Options flag = {0};
    if (ParseFlags(argc, argv, &flag)) {
      OpenFile(argc, argv, &flag);
    }
  }
  return 0;
}

int ParseFlags(int argc, char* argv[], Options* flag) {
  int opt;
  int status = 1;
  while ((opt = getopt_long(argc, argv, "beEnstT", long_option, NULL)) != -1 &&
         status) {
    switch (opt) {
      case 'b':
        flag->b_option = 1;
        break;
      case 'e':
        flag->E_option = 1;
        flag->v_option = 1;
        break;
      case 'E':
        flag->E_option = 1;
        break;
      case 'n':
        flag->n_option = 1;
        break;
      case 's':
        flag->s_option = 1;
        break;
      case 't':
        flag->T_option = 1;
        flag->v_option = 1;
        break;
      case 'T':
        flag->T_option = 1;
        break;
      default:
        status = 0;
        break;
    }
  }
  return status;
}

FILE* PrintFile(FILE* file, Options* flag) {
  unsigned char c = ' ';
  int count = 1;
  flag->new_line = 1;
  while ((c = fgetc(file)) != 255) {
    if (flag->n_option || flag->b_option || flag->s_option) {
      if (flag->new_line && flag->n_option) {
        printf("%6d\t", count++);
        flag->new_line = 0;
      } else if (flag->new_line && flag->b_option && c != '\n') {
        printf("%6d\t", count++);
        flag->new_line = 0;
      } else if (flag->new_line && flag->s_option && c != '\n') {
        flag->new_line = 0;
      }
      if (c == '\n') {
        flag->new_line++;
      }
    }
    if (flag->v_option) {
      c = vOption(c);
    }
    if (flag->b_option && c == '\n') {
      printf("\n");
    } else if (flag->s_option && flag->new_line > 2 && c == '\n') {
      continue;
    } else if (flag->E_option && c == '\n') {
      printf("$\n");
    } else if (flag->T_option && c == '\t') {
      printf("^I");
    } else {
      printf("%c", c);
    }
  }
  return file;
}

void OpenFile(int argc, char* argv[], Options* flag) {
  for (int i = optind; i < argc; i++) {
    FILE* file = fopen(argv[i], "r");
    if (file) {
      fclose(PrintFile(file, flag));
    } else {
      fprintf(stderr, ERROR_01, argv[i]);
    }
  }
}

unsigned char vOption(unsigned char c) {
  if ((c < 32 || c == 127) && c != 9 && c != 10) {
    c = c ^ 0b01000000;
    printf("^");
  }
  if (c > 127) {
    c = c ^ 0b11000000;
    printf("M-^");
  }
  return c;
}
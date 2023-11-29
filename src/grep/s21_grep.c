#include "s21_grep.h"

int main(int argc, char* argv[]) {
  Options flag = {0};
  if (ParseFlags(argc, argv, &flag)) {
    OpenFile(argc, argv, &flag);
  }
  return 0;
}

int ParseFlags(int argc, char* argv[], Options* flag) {
  int opt;
  int status = 1;
  while ((opt = getopt_long(argc, argv, "e:ivcln", 0, NULL)) != -1 && status) {
    switch (opt) {
      case 'e':
        flag->e_option = 1;
        strcat(flag->str_patterns, optarg);
        strcat(flag->str_patterns, "|");
        break;
      case 'i':
        flag->i_option = 1;
        break;
      case 'v':
        flag->v_option = 1;
        break;
      case 'c':
        flag->c_option = 1;
        break;
      case 'l':
        flag->l_option = 1;
        break;
      case 'n':
        flag->n_option = 1;
        break;
      default:
        status = 0;
        break;
    }
  }
  if (!flag->e_option) {
    if (optind < argc) {
      strcat(flag->str_patterns, argv[optind]);
      optind++;
    }
  }
  if (flag->e_option) {
    flag->str_patterns[strlen(flag->str_patterns) - 1] = '\0';
  }
  return status;
}

void OpenFile(int argc, char* argv[], Options* flag) {
  while (optind < argc) {
    FILE* file = fopen(argv[optind], "r");
    if (file) {
      fclose(PrintFile(file, flag, argv[optind]));
    } else {
      fprintf(stderr, ERROR_01, argv[optind]);
      optind = argc;
    }
    optind++;
  }
}

FILE* PrintFile(FILE* file, Options* flag, char* argv) {
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  regex_t reg;
  int count = 0;
  int number = 0;
  int reg_flag;
  char print_line[BUFFER] = "";
  if (flag->i_option) {
    reg_flag = REG_ICASE;
  } else {
    reg_flag = REG_EXTENDED;
  }
  regcomp(&reg, flag->str_patterns, reg_flag);
  while ((read = getline(&line, &len, file)) != -1) {
    count++;
    if (!regexec(&reg, line, 0, NULL, 0)) {
      number++;
      if (flag->n_option && !flag->c_option && !flag->l_option &&
          !flag->v_option) {
        printf("%d:", count);
      }
      if (!flag->c_option && !flag->l_option && !flag->v_option) {
        strcpy(print_line, line);
        printf("%s", line);
      }
    } else if (flag->v_option && flag->n_option) {
      printf("%d:", count);
      strcpy(print_line, line);
      printf("%s", line);
    } else if (flag->v_option && !flag->c_option && !flag->l_option) {
      strcpy(print_line, line);
      printf("%s", line);
    }
  }
  if (flag->c_option && !flag->l_option && !flag->v_option) {
    printf("%d\n", number);
  } else if (flag->l_option && number) {
    printf("%s\n", argv);
  } else if (flag->v_option && flag->c_option) {
    printf("%d\n", count - number);
  }
  if (!strcmp(print_line, line)) {
    printf("\n");
  }
  regfree(&reg);
  free(line);
  return file;
}
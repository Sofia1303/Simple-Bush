CC = gcc -Wall -Werror -Wextra -std=c11

all: s21_cat

rebuild: clean all

s21_cat: s21_cat.c
	$(CC) s21_cat.c -o s21_cat

clean: 
	rm -f s21_cat
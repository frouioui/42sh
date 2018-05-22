/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** include file of the libmy functions
*/

#ifndef LIBMY_H
#define LIBMY_H

#include <stdbool.h>
#include "shell.h"

int my_strlen(char *);
void my_putstr(char *);
void my_putchar(char);
int my_strcmp(char *, char *);
char *get_next_line(int);
unsigned int my_number_row(char **);
char *my_strcpy(char *, char *);
char *my_get_env(char **, char *);
char **cut_line(char *);
unsigned int get_line_env(char **, char *);
unsigned int get_line_env_zero(char **, char *);
char *my_getenv_root(char *);
int my_atoi(char *);
bool my_ischar(char c);
int my_strcmp_env(char *str, char *env);
char *my_get_env_parse(char **, int);
char *my_strcat(char *, char *);
char **my_seg_path(char *);

#endif /* end of include guard: LIBMY_H */

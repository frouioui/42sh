/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file of the input functions.
*/

#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include "shell.h"

#define CLEAR_END_LINE "\033[K"

char *get_input(shell_t *, int);
char *get_chars_from_term(shell_t *, int);
char *regular_char(char *, int, int *, int);
int cursor_moves(char *, int, int *, binding_t *);

#endif /* end of include guard: INPUT_H */

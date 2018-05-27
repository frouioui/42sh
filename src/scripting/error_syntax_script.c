/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Print syntax error
*/

#include "script.h"
#include "mylib.h"

void print_error_syntax(cond_t *cond_line)
{
	cond_t cond_array[NB_COND] = {{IF, "if", NULL, false},
		{ELSE, "else", NULL, false}, {WHILE, "while", NULL, false},
		{FOREACH, "foreach", NULL, false},
		{WHICH, "which", NULL, false}, {WHERE, "where", NULL, false}};

	for (int i = 0; i < NB_COND; i += 1) {
		if (cond_line->key == cond_array[i].key) {
			my_putstr(cond_array[i].condition);
			puts(": Expression Syntax.");
		}
	}
}

static void print_error(char *var)
{
	my_putstr(var);
	puts(": Undefined variable.");
}

void print_error_var(char *var_one, char *var_two, int value_one,
	int value_two)
{
	if (value_one == -1)
		print_error(var_one);
	else if (value_two == -1)
		print_error(var_two);
}

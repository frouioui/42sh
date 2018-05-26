/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check equal and diff conditions
*/

#include "script.h"

static int compare_value(int value_one, int value_two)
{
	if (value_one == value_two)
		return (SUCCESS);
	return (SKIP);
}

static int compare_string(char *var_one, char *var_two)
{
	if (!strcmp(var_one, var_two))
		return (SUCCESS);
	return (SKIP);
}

int op_sup(shell_t *shell, cond_t *cond_line, char *var_one, char *var_two)
{
	int value_one = 0;
	int value_two = 0;

	if (var_one[0] != '$' || var_two[0] != '$')
		return (compare_string(var_one, var_two));
	if (var_one[0] = '$')
		value_one = get_value_from_var(shell, var_one);
	if (var_two[0] = '$')
		value_two = get_value_from_var(shell, var_two);
	if (value_one == -1 || value_two == -1) {
		print_error_syntax(cond_line);
		return (FAILURE);
	}
	return (compare_value(value_one, value_two));
}

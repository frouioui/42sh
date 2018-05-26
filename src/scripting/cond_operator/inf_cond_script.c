/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check inferior conditions
*/

#include "script.h"

static int compare_value(int value_one, int value_two)
{
	if (value_one < value_two)
		return (SUCCESS);
	return (SKIP);
}

static int compare_string(char *var_one, char *var_two)
{
	if (strcmp(var_one, var_two) < 0)
		return (SUCCESS);
	return (SKIP);
}

static int get_value(shell_t *shell, char **local_var)
{
	int value = 0;

	if (!(*local_var))
		return (-1);
	if ((*local_var)[0] == '$') {
		*local_var = sup_value_symbol(*local_var);
		value = get_value_from_var(shell, *local_var);
	} else
		value = atoi(*local_var);
	return (value);
}

int op_inf(shell_t *shell, cond_t *cond_line, char **var_one, char **var_two)
{
	int value_one = 0;
	int value_two = 0;

	if ((*var_one)[0] != '$' && (*var_two)[0] != '$')
		return (compare_string(*var_one, *var_two));
	value_one = get_value(shell, var_one);
	value_two = get_value(shell, var_two);
	if (value_one == -1 || value_two == -1) {
		print_error_var(*var_one, *var_two, value_one, value_two);
		return (FAILURE);
	}
	return (compare_value(value_one, value_two));
}

/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Return true if the argument is a builtin.
*/

#include <stdbool.h>
#include "mylib.h"

bool is_builtins(char *arg)
{
	if (my_strcmp(arg, "cd") && my_strcmp(arg, "env") &&
	my_strcmp(arg, "setenv") && my_strcmp(arg, "exit") &&
	my_strcmp(arg, "unsetenv")) {
		return (false);
	}
	return (true);
}

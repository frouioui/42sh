/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Return true if the argument is a builtin.
*/

#include <stdbool.h>
#include <string.h>

bool is_builtins(char *arg)
{
	if (strcmp(arg, "cd") != 0 && strcmp(arg, "env") != 0 &&
	strcmp(arg, "setenv") != 0 && strcmp(arg, "exit") != 0 &&
	strcmp(arg, "unsetenv") != 0 && strcmp(arg, "echo") != 0 &&
	strcmp(arg, "history") != 0 && strcmp(arg, "alias") != 0 &&
	strcmp(arg, "set") != 0 && strcmp(arg, "unset") != 0 &&
	strcmp(arg, "fg") != 0 && strcmp(arg, "jobs")) {
		return (false);
	}
	return (true);
}

/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Check the quote in the sub strings of the pipe
*/

#include "mylib.h"

static void remove_first(char *arg)
{
	unsigned int i = 0;

	for (i = 0; arg[i + 1]; i++)
		arg[i] = arg[i + 1];
	arg[i] = '\0';
}

void check_quote(char **args)
{
	for (unsigned int i = 0; args[i]; i++) {
		if (args[i][0] == '"')
			remove_first(args[i]);
		if (args[i][my_strlen(args[i]) - 1] == '"')
			args[i][my_strlen(args[i]) - 1] = '\0';
	}
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get direct match with the binding structure
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "execution.h"
#include "input.h"

static void check_clear(int c, char *input, int *i, shell_t *shell)
{
	if (c == shell->binding->clear) {
		write(0, "\033c", 2);
		display_prompt(shell);
		write(0, input, strlen(input));
	}
}

static void check_exit(int c, char *input, int *i, shell_t *shell)
{
	if (c == shell->binding->exit) {
		exit_built(shell, NULL);
		for (int a = 0; a < *i; a++)
			my_putstr("\033[1D");
		my_putstr(CLEAR_END_LINE);
		write(0, "exit", strlen("exit"));
		free(input);
		input = strdup("exit");
		*i = strlen(input);
	}
}

void check_match_direct(char *input, int c, int *i, shell_t *shell)
{
	check_clear(c, input, i, shell);
	check_exit(c, input, i, shell);
}

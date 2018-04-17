/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Unset the given key on the env.
*/

#include <stdlib.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static int display_unsetenv_error(shell_t *shell)
{
	shell->code = 1;
	my_putstr("unsetenv: Too few arguments.\n");
	return (0);
}

int unsetenv_built(shell_t *shell, pipe_t *pipe)
{
	int pos = 0;

	if (pipe->args[1] == NULL)
		return (display_unsetenv_error(shell));
	pos = get_line_env(shell->env, pipe->args[1]);
	while (shell->env[pos] != NULL) {
		shell->env[pos] = shell->env[pos + 1];
		pos++;
	}
	return (0);
}

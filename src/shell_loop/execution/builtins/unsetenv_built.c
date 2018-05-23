/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unset the given key on the env. Returns if there is an error.
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static int display_unsetenv_error(shell_t *shell, int fd)
{
	char str[] = "unsetenv: Too few arguments.\n";

	shell->code = 1;
	write(fd, str, strlen(str));
	return (-1);
}

int unsetenv_built(shell_t *shell, pipe_t *pipe)
{
	int pos = 0;

	if (pipe->args[1] == NULL)
		return (display_unsetenv_error(shell, pipe->fd));
	pos = get_line_env(shell->env, pipe->args[1]);
	while (shell->env[pos] != NULL) {
		shell->env[pos] = shell->env[pos + 1];
		pos++;
	}
	return (0);
}

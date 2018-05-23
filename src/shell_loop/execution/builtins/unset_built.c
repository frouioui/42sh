/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unset one variable on the local env
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

static int display_unset_error(shell_t *shell, int fd)
{
	char str[] = "unset: Too few arguments.\n";

	shell->code = 1;
	write(fd, str, strlen(str));
	return (-1);
}

int unset_built(shell_t *shell, pipe_t *pipe)
{
	int pos = 0;

	if (pipe->args[1] == NULL)
		return (display_unset_error(shell, pipe->fd));
	for (int i = 0; pipe->args[i]; i++) {
		pos = get_pos_key(pipe->args[i], shell->local);
		while (pos != -1 && shell->local[pos] != NULL) {
			shell->local[pos] = shell->local[pos + 1];
			pos++;
		}
	}
	return (0);
}

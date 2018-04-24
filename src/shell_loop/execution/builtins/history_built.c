/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Execute the history builtin.
*/

#include <stdlib.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static void display_full_history(shell_t *shell, int fd)
{
	char **history = get_whole_history();
	unsigned int size = size_history();

	if (history == NULL)
		return;
	for (unsigned int i = 0; history[i]; i++) {
		write(fd, history[i], strlen(history[i]));
		write(fd, "\n", 1);
	}
}

int history_built(shell_t *shell, pipe_t *pipe)
{
	if (pipe->args[1] == NULL) {
		display_full_history(shell, pipe->fd);
	}
}

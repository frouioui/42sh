/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Display a text line
*/

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "mylib.h"

static bool search_option(pipe_t *pipe, int *index)
{
	if (pipe->args[1] != NULL) {
		if (strcmp(pipe->args[1], "-n") == 0) {
			*index += 1;
			return (true);
		}
	}
	return (false);
}

static void write_args(pipe_t *pipe)
{
	int index = 1;
	bool n_option = false;

	check_quote(pipe->args);
	n_option = search_option(pipe, &index);
	while (pipe->args[index] != NULL &&
	pipe->args[index + 1] != NULL) {
		write(pipe->fd, pipe->args[index],
			strlen(pipe->args[index]));
		write(pipe->fd, " ", 1);
		index += 1;
	}
	if (pipe->args[index] != NULL)
		write(pipe->fd, pipe->args[index], strlen(pipe->args[index]));
	if (n_option != true)
		write(pipe->fd, "\n", 1);
}

int echo_built(shell_t *shell, pipe_t *pipe)
{
	if (pipe->args[1] == NULL)
		write(pipe->fd, "\n", 1);
	else {
		write_args(pipe);
	}
	return (0);
}

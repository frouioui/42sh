/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Execute the history builtin.
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

/* integration of the shell struct for future use (variable size_history) */
static void display_full_history(shell_t *shell, int fd)
{
	char **history = get_whole_history();

	if (history == NULL)
		return;
	for (unsigned int i = 0; history[i]; i++) {
		write(fd, history[i], strlen(history[i]));
		write(fd, "\n", 1);
	}
}

/* integration of the shell struct for future use (variable size_history) */
static void display_line_history(shell_t *shell, int fd, int line_display)
{
	char **history = get_whole_history();
	unsigned int size = size_history();

	if (history == NULL)
		return;
	if (line_display >= (int)size) {
		free_array_string(history);
		display_full_history(shell, fd);
		return;
	}
	for (int i = size - line_display; history[i]; i++) {
		write(fd, history[i], strlen(history[i]));
		write(fd, "\n", 1);
	}
}

static void error_history(int fd)
{
	char str[] = "history: Cannot find the history file.\n";

	write(fd, str, strlen(str));
}

int history_built(shell_t *shell, pipe_t *pipe)
{
	if (pipe->args[1] == NULL)
		display_full_history(shell, pipe->fd);
	else if (pipe->args[1] != NULL && pipe->args[2] == NULL)
		display_line_history(shell, pipe->fd, atoi(pipe->args[1]));
	else
		error_history(pipe->fd);
}

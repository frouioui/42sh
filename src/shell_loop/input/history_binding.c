/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** History binding functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "execution.h"
#include "input.h"

static char *get_line_history(shell_t *shell, int hist_i)
{
	char **history = get_whole_history(shell->paths);
	unsigned int size = size_history(shell->paths);
	char *input = NULL;
	int i = 0;

	if (history == NULL)
		return (NULL);
	if (hist_i > (int)size - 1)
		return (NULL);
	i = size - 1 - hist_i;
	if (history[i] == NULL) {
		free_array_string(history);
		return (NULL);
	}
	input = strdup(history[i]);
	free_array_string(history);
	return (input);
}

static char *up_history(shell_t *shell, char *input, int *i, int *hist_i)
{
	char *new = NULL;

	new = get_line_history(shell, *hist_i);
	if (new == NULL)
		return (input);
	for (int i = 0; i < (int)strlen(input); i++)
		my_putstr("\033[1D");
	my_putstr(CLEAR_END_LINE);
	write(0, new, strlen(new));
	*i = strlen(new);
	(*hist_i)++;
	free(input);
	return (new);
}

static char *down_history(shell_t *shell, char *input, int *i, int *hist_i)
{
	char *new = NULL;

	new = get_line_history(shell, (*hist_i) - 1);
	if (new == NULL)
		return (input);
	for (int i = 0; i < (int)strlen(input); i++)
		my_putstr("\033[1D");
	my_putstr(CLEAR_END_LINE);
	write(1, new, strlen(new));
	*i = strlen(new);
	(*hist_i)--;
	free(input);
	return (new);
}

char *history_binding(char *input, int c, int *i, shell_t *shell)
{
	static int hist_i = 0;
	int buf = 0;

	if (c == EOT || c == '\n') {
		hist_i = buf;
		return (input);
	}
	if (c != shell->binding->up && c != shell->binding->down)
		return (input);
	if (c == shell->binding->up)
		input = up_history(shell, input, i, &hist_i);
	if (c == shell->binding->down)
		input = down_history(shell, input, i, &hist_i);
	return (input);
}

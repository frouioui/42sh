/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** Set local var builtin
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"

static int display_variable(shell_t *shell, int fd)
{
	for (unsigned int i = 0; shell->local[i]; i++)
		puts(shell->local[i]);
	return (0);
}

static char *concate_key_value(char *arg)
{
	char *full = NULL;
	int a = 0;
	int i = 0;

	if (ALPHA(arg[0]) == 0)
		return (NULL);
	full = malloc(sizeof(char) * (strlen(arg) + 2));
	if (full == NULL)
		return (NULL);
	full[a] = '\0';
	for (; arg[i] && arg[i] != '='; i++, a++)
		full[a] = arg[i];
	if (arg[i] != '\0') {
		full[a++] = '\t';
		i++;
	}
	for (; arg[i]; i++, a++)
		full[a] = arg[i];
	full[a] = '\0';
	return (full);
}


static int set_one_variable(shell_t *shell, char *arg)
{
	char *full = concate_key_value(arg);
	int pos = 0;
	char *key = NULL;

	if (full == NULL || !(key = malloc(sizeof(char) * strlen(full) + 1)))
		return (-1);
	for (int i = 0; full[i] && full[i] != '\t'; i++) {
		key[i] = full[i];
		key[i + 1] = '\0';
	}
	pos = get_pos_key(key, shell->local);
	if (pos != -1) {
		free(shell->local[pos]);
		shell->local[pos] = full;
		return (0);
	}
	for (pos = 0; shell->local[pos]; pos++);
	shell->local = realloc_env(shell->local, pos, strlen(full) + 1);
	strcpy(shell->local[pos], full);
	return (0);
}

int get_pos_key(char *key, char **local)
{
	int i = 0;

	for (int pos = 0; local[pos]; pos++) {
		for (i = 0; key[i] && local[pos][i] && local[pos][i]
			!= '\t'; i++);
		if (key[i] == '\0' && (local[pos][i] == '\0' ||
			local[pos][i] == '\t'))
			return (pos);
	}
	return (-1);
}

int set_built(shell_t *shell, pipe_t *pipe)
{
	if (pipe->args[1] == NULL)
		return (display_variable(shell, pipe->fd));
	if (pipe->args[1] && pipe->args[2] != NULL)
		for (int i = 1; pipe->args[i]; i++)
			set_one_variable(shell, pipe->args[i]);
	if (pipe->args[1] && pipe->args[2] == NULL)
		return (set_one_variable(shell, pipe->args[1]));
	return (0);
}

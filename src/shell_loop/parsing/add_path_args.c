/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Add new path in pipe structure
*/

#include <stdlib.h>
#include "instruction.h"
#include "globbing.h"
#include "shell.h"

static int realloc_pipe_args(args_list_t *list, pipe_t *pipe, int size)
{
	args_list_t *tmp = list;

	free_array_string(pipe->args);
	pipe->args = NULL;
	pipe->args = malloc(sizeof(char *) * (size + 1));
	if (!pipe->args)
		return (FAILURE);
	for (int i = 0; i < size; i += 1, tmp = tmp->next)
		pipe->args[i] = strdup(tmp->arg);
	pipe->args[size] = NULL;
	return (SUCCESS);
}

int add_path_in_pipe(args_list_t *list, pipe_t *pipe)
{
	args_list_t *tmp = list;
	int size = 0;

	while (tmp != NULL) {
		size += 1;
		tmp = tmp->next;
	}
	if (realloc_pipe_args(list, pipe, size) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

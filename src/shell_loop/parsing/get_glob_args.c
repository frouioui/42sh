/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Globbings functions
*/

#include <stdlib.h>
#include "instruction.h"
#include "globbing.h"
#include "shell.h"

static int replace_glob_args(pipe_t *pipe)
{
	args_list_t *args_list = built_list(pipe);
	args_list_t *tmp = NULL;

	if (!args_list)
		return (FAILURE);
	tmp = args_list;
	while (tmp != NULL) {
		if (search_glob_args(args_list, tmp->arg) == FAILURE)
			return (FAILURE);
		tmp = tmp->next;
	}
	if (add_path_in_pipe(args_list, pipe) == FAILURE)
		return (FAILURE);
	free_args_list(args_list);
	return (SUCCESS);
}

int get_glob_args(pipe_t **pipe)
{
	for (int i = 0; pipe[i]; i += 1) {
		if (replace_glob_args(pipe[i]) != SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}

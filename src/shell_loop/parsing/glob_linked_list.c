/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Create and destroy chained list
*/

#include "instruction.h"
#include "globbing.h"
#include "shell.h"
#include <stdlib.h>
#include <string.h>

static int insert_link(args_list_t *tmp, char *new_path)
{
	args_list_t *new_arg = malloc(sizeof(*new_arg));

	if (!new_arg)
		return (FAILURE);
	new_arg->arg = strdup(new_path);
	if (!new_arg->arg)
		return (FAILURE);
	if (tmp->next != NULL) {
		new_arg->next = tmp->next->next;
		free(tmp->next->arg);
		free(tmp->next);
	} else
		new_arg->next = NULL;
	tmp->next = new_arg;
	return (SUCCESS);
}

args_list_t *add_new_path(args_list_t *list, char *pattern, char **glob_path)
{
	args_list_t *tmp = list;

	while (tmp->next != NULL && strcmp(tmp->next->arg, pattern) != 0)
		tmp = tmp->next;
	for (int i = 0; glob_path[i] != NULL; i += 1) {
		if (insert_link(tmp, glob_path[i]) == FAILURE) {
			free_args_list(list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (list);
}

static args_list_t *add_new_arg(args_list_t *list, char *arg)
{
	args_list_t *new_arg = malloc(sizeof(*new_arg));
	args_list_t *tmp = list;

	if (!new_arg)
		return (NULL);
	new_arg->arg = strdup(arg);
	if (!new_arg->arg)
		return (NULL);
	new_arg->next = NULL;
	if (!list)
		return (new_arg);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_arg;
	return (list);
}

args_list_t *built_list(pipe_t *pipe)
{
	args_list_t *args_list = NULL;

	for (int i = 0; pipe->args[i]; i += 1) {
		if (!(args_list = add_new_arg(args_list, pipe->args[i]))) {
			free_args_list(args_list);
			return (NULL);
		}
	}
	return (args_list);
}

void free_args_list(args_list_t *list)
{
	args_list_t *tmp = list;

	if (!list)
		return;
	while (list != NULL && tmp != NULL) {
		tmp = list->next;
		free(list->arg);
		free(list);
		list = NULL;
		if (tmp)
			tmp = tmp->next;
	}
}

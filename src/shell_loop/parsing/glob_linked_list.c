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

args_list_t *add_new_path(args_list_t *old_args, args_list_t *new_args,
args_list_t **tmp)
{
	args_list_t *old_tmp = old_args;
	args_list_t *new_tmp = new_args;

	while (old_tmp->next != NULL &&
	strcmp(old_tmp->next->arg, (*tmp)->arg) != 0)
		old_tmp = old_tmp->next;
	*tmp = old_tmp->next->next;
	while (new_tmp->next != NULL)
		new_tmp = new_tmp->next;
	new_tmp->next = old_tmp->next->next;
	free(old_tmp->next->arg);
	free(old_tmp->next);
	old_tmp->next = new_args;
	return (old_args);
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

args_list_t *built_list(char **args)
{
	args_list_t *args_list = NULL;

	for (int i = 0; args[i]; i += 1) {
		if (!(args_list = add_new_arg(args_list, args[i]))) {
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
		tmp = list;
		list = list->next;
		free(tmp->arg);
		free(tmp);
	}
}

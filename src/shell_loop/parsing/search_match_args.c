/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Research of globbing symbols
*/

#include <stdlib.h>
#include "instruction.h"
#include "globbing.h"
#include "shell.h"

static int add_link_to_list(args_list_t *args_list, args_list_t **tmp)
{
	glob_t globbing;
	args_list_t *new_args = NULL;

	globbing.gl_offs = 0;
	if (glob((*tmp)->arg, GLOB_TILDE_CHECK, NULL, &globbing) != 0)
		return (SKIP);
	new_args = built_list(globbing.gl_pathv);
	if (!new_args)
		return (FAILURE);
	if (!(args_list = add_new_path(args_list, new_args, tmp)))
		return (FAILURE);
	globfree(&globbing);
	return (SUCCESS);
}

static bool search_glob_symbols(char *arg)
{
	for (int i = 0; arg[i] != '\0'; i += 1) {
		if (GLOB(arg[i]))
			return (true);
	}
	return (false);
}

int search_glob_args(args_list_t *args_list, args_list_t **tmp)
{
	if (search_glob_symbols((*tmp)->arg)) {
		if (add_link_to_list(args_list, tmp) == FAILURE)
			return (FAILURE);
	} else
		*tmp = (*tmp)->next;
	return (SUCCESS);
}

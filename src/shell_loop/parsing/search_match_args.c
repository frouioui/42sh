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

static int add_link_to_list(args_list_t *args_list, char *pattern)
{
	glob_t globbing;

	globbing.gl_offs = 0;
	if (glob(pattern, GLOB_TILDE_CHECK, NULL, &globbing) != 0)
		return (SKIP);
	if (!(args_list = add_new_path(args_list, pattern, globbing.gl_pathv)))
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

int search_glob_args(args_list_t *args_list, char *pattern)
{
	if (search_glob_symbols(pattern)) {
		if (add_link_to_list(args_list, pattern) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

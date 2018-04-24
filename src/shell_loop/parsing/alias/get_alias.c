/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check if there is an aliase inside the given pipe
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "alias.h"
#include "mylib.h"

static bool alias_match(char *arg, char **key)
{
	for (int i = 0; key[i]; i++) {
		if (strcmp(arg, key[i]) == 0)
			return (true);
	}
	return (false);
}

char **get_alias_match(char **args, char ***alias)
{
	char **new_args = NULL;
	char *new_input = NULL;

	for (int i = 0; alias[0][i] && new_input == NULL; i++) {
		if (strcmp(args[i], alias[0][i]) == 0) {
			new_input = strdup(alias[1][i]);
		}
	}
	if (new_input == NULL) {
		free_array_string(args);
		return (NULL);
	}
	new_args = cut_line(new_input);
	free_array_string(args);
	free(new_input);
	return (new_args);
}

char **get_alias(char **args)
{
	char ***alias = get_alias_from_file();

	if (alias_match(args[0], alias[0]) == true) {
		return (get_alias_match(args, alias));
	}
	return (args);
}

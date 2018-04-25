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

static void free_alias(char ***alias)
{
	for (int i = 0; alias[1][i] && alias[0][i]; i++) {
		free(alias[1][i]);
		free(alias[0][i]);
	}
	free(alias[1]);
	free(alias[0]);
	free(alias);
}

char *get_alias_match(char **args, char *user_input, char ***alias)
{
	char *new_input = NULL;

	for (int i = 0; alias[0][i] && new_input == NULL; i++) {
		if (strcmp(args[0], alias[0][i]) == 0) {
			new_input = strdup(alias[1][i]);
		}
	}
	free_alias(alias);
	if (new_input == NULL) {
		return (user_input);
	}
	free(user_input);
	return (new_input);
}

char *get_alias(char **args, char *user_input)
{
	char ***alias = get_alias_from_file();

	if (alias_match(args[0], alias[0]) == true) {
		return (get_alias_match(args, user_input, alias));
	}
	return (user_input);
}

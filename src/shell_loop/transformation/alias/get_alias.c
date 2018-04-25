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

bool alias_match(char *arg, char **key)
{
	if (arg == NULL || key == NULL || key[0] == NULL)
		return (false);
	for (int i = 0; key && arg && key[i]; i++) {
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

static char *add_end_string(char **args, char *new_input)
{
	char *end = NULL;
	int size = 0;

	for (int i = 1; args[i]; i++)
		size += strlen(args[i]);
	end = malloc(sizeof(char) * (strlen(new_input) + (size * 2) + 1));
	if (end == NULL)
		return (NULL);
	for (int i = 0; new_input[i]; i++) {
		end[i] = new_input[i];
		end[i + 1] = '\0';
	}
	for (int i = 1; args[i]; i++) {
		end = strcat(end, " ");
		end = strcat(end, args[i]);
	}
	free(new_input);
	return (end);
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
	new_input = add_end_string(args, new_input);
	free(user_input);
	return (new_input);
}

/*
** Returns the new user_input if there is an alias, returns NULL if error.
** Returns the same string if there is no alias.
** The char* home variable define the path of the .alias file. The path is
** defined at the initialisation of the shell.
*/
char *get_alias(char **args, char *user_input, char *home)
{
	char ***alias = get_alias_from_file(home);

	if (alias && alias_match(args[0], alias[0]) == true) {
		return (get_alias_match(args, user_input, alias));
	}
	return (user_input);
}

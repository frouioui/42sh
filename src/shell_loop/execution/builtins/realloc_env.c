/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Realloc the whole environement and returns it
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mylib.h"

char **realloc_env(char **old_env, int pos, int size_pos)
{
	char **env = malloc(sizeof(char *) * (pos + 2));

	if (env == NULL)
		exit(84);
	for (int i = 0; old_env[i] != NULL; i++) {
		env[i] = strdup(old_env[i]);
		if (env[i] == NULL)
			exit(84);
		free(old_env[i]);
	}
	free(old_env);
	env[pos] = malloc(size_pos);
	if (env[pos] == NULL)
		exit(84);
	env[pos + 1] = NULL;
	return (env);
}

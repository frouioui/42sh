/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Init all the paths inside the shell
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

static char *init_alias_home(char **env)
{
	char *home = my_get_env(env, "HOME");
	char *path = my_strcpy(NULL, "/.alias");
	char *alias = malloc(sizeof(char) * (strlen(path) + strlen(home) + 1));
	int i = 0;

	for (int a = 0; home[a]; a++) {
		alias[i] = home[a];
		i++;
	}
	for (int a = 0; path[a]; a++) {
		alias[i] = path[a];
		i++;
	}
	alias[i] = '\0';
	return (alias);
}

char **init_paths(char **env)
{
	char **paths = malloc(sizeof(char *) * 2);

	paths[0] = init_alias_home(env);
	paths[1] = NULL;
	return (paths);
}

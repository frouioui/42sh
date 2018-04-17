/*
** EPITECH PROJECT, 2017
** save_old_pwd.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"

void save_old_pwd(char **env)
{
	unsigned int pos_old_pwd = get_line_env(env, "OLDPWD");
	char *current = my_get_env(env, "PWD");
	char name[] = "OLDPWD=";
	int j = 0;

	current == NULL ? current = my_strcpy(NULL, "\0") : 0;
	free(env[pos_old_pwd]);
	env[pos_old_pwd] = malloc(sizeof(char) * (my_strlen(current) + 8));
	if (env[pos_old_pwd] == NULL)
		exit(84);
	for (int i = 0; name[i]; i++) {
		env[pos_old_pwd][j] = name[i];
		j++;
	}
	for (int i = 0; current[i]; i++) {
		env[pos_old_pwd][j] = current[i];
		j++;
	}
	env[pos_old_pwd][j] = '\0';
}

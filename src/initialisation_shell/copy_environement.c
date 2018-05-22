/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

char **copy_environement(char **origin)
{
	unsigned int number_row = my_number_row(origin);
	char **env = malloc(sizeof(char *) * (number_row + 1));

	if (env == NULL)
		return (NULL);
	for (unsigned int i = 0; i < number_row; i++) {
		env[i] = malloc(sizeof(char) * (strlen(origin[i]) + 1));
		if (env[i] == NULL)
			return (NULL);
		strcpy(env[i], origin[i]);
		env[i + 1] = NULL;
	}
	env[number_row] = NULL;
	return (env);
}

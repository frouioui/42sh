/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Get the root of the env
*/

#include <stdlib.h>
#include "mylib.h"

char *my_getenv_root(char *str)
{
	char *root = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i;

	if (root == NULL)
		return (NULL);
	for (i = 0; str[i] && str[i] != '='; i++)
		root[i] = str[i];
	root[i++] = '=';
	root[i] = '\0';
	return (root);
}

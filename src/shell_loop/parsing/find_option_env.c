/*
** EPITECH PROJECT, 2017
** find_option_env.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

int find_option_env(char **env, char *str)
{
	if (str == NULL || env == NULL)
		return (-1);
	for (int i = 0; env[i] != NULL; i++) {
		if (!my_strcmp_env(str, env[i]))
			return (i);
	}
	return (-2);
}

int find_separator_env(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (!my_ischar(str[i]))
			return (i);
	}
	return (i);
}

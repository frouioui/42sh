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
		if (!strcmp(str, env[i]))
			return (i);
	}
	return (-2);
}

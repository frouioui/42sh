/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Returns 0 is same and 1 if different.
*/

#include <stdlib.h>
#include "mylib.h"

int my_strcmp_env(char *str, char *env)
{
	int i = 0;

	if (str == NULL || env == NULL)
		return (1);
	for (i = 0; str[i] != '\0' && env[i] != '\0' && env[i] != '=' &&
		env[i] != '\t'; i++) {
		if (str[i] != env[i])
			return (1);
	}
	if (env[i] != '=' && env[i] != '\t' && str[i] != '\0')
		return (1);
	return (0);
}

int my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 == NULL)
		return (1);
	if (my_strlen(s1) != my_strlen(s2))
		return (1);
	while (s1[i] != '\0') {
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return (1);
		i = i + 1;
	}
	return (0);
}

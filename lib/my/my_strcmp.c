/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Returns 0 is same and 1 if different.
*/

#include <stdlib.h>
#include "mylib.h"

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

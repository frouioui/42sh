/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Concatenate two strings
*/

#include <stdlib.h>
#include "mylib.h"

char *my_strcat(char *s1, char *s2)
{
	char *res = malloc(sizeof(char) * my_strlen(s1) + my_strlen(s2) + 1);
	int i = 0;
	int a = 0;

	if (s1 == NULL || s2 == NULL)
		return (s1 == NULL && s2 != NULL ? s2 + 1 : NULL);
	while (s1[i]) {
		res[i] = s1[i];
		res[i + 1] = '\0';
		i++;
	}
	for (a = i; s2[a]; a++) {
		res[i] = s2[a];
		res[i + 1] = '\0';
		i++;
	}
	free(s1);
	return (res);
}

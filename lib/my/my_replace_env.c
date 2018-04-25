/*
** EPITECH PROJECT, 2017
** my_replace_env.c
** File description:
** florian.davasse@epitech.eu
*/

#include "mylib.h"

char *my_replace_env(char *, char *src)
{
	int i = 0;

	if (dest == NULL)
		dest = malloc(sizeof(char) * my_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; src[i] != '\0'; i += 1) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

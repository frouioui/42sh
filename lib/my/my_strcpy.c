/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Function that copies a string into another
*/

#include <stdlib.h>
#include "mylib.h"

char *my_strcpy(char *dest, char *src)
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

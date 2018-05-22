/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Returns the lenght of the given string.
*/

#include <stdlib.h>

int my_strlen(char *str)
{
	int size = 0;

	if (str == NULL)
		return (0);
	while (str[size] != '\0') {
		size++;
	}
	return (size);
}

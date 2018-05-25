/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Free a whole (char **) pointer
*/

#include <stdlib.h>

void free_array_string(char **array)
{
	if (!array)
		return;
	for (int i = 0; array[i]; i++) {
		free(array[i]);
	}
	free(array);
}

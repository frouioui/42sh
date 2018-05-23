/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** Init the shell's local variables
*/

#include <stdlib.h>

char **init_local(void)
{
	char **local = malloc(sizeof(char *));

	if (local == NULL)
		return (NULL);
	local[0] = NULL;
	return (local);
}

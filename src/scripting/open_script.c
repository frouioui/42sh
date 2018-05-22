/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Open script file
*/

#include "script.h"

FILE *open_script(char *path)
{
	FILE *fd = NULL;

	if (!path)
		return (NULL);
	if (!(fd = fopen(path, "r")))
		return (NULL);
	return (fd);
}

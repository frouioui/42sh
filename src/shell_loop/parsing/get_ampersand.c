/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_ampersand.c --> find if there is an ampersand and clean
*/

#include <stdlib.h>
#include "shell.h"

void get_ampersand(pipe_t *pipe)
{
	if (!pipe)
		return;
	if (!pipe->args)
		return;
	for (int i = 0; pipe->args[i]; i++) {
		if (strstr(pipe->args[i], "&") == NULL)
			continue;
		pipe->ampersand = true;
		for (int j = 0; pipe->args[i][j]; pipe->args[i][j++] = 0);
		free(pipe->args[i]);
		pipe->args[i] = NULL;
		}
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Open script file
*/

#include "script.h"
#include "shell.h"
#include <stdio.h>

bool run_script(char *path)
{
	FILE *fd = fopen(path, "r");

	if (!fd)
		return (false);
	fclose(fd);
	return (true);
}

void redirect_script(shell_t *shell, FILE *fd)
{

}

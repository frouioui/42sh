/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Run script
*/

#include "script.h"

char *run_script(shell_t *shell, FILE *fd)
{
	char *line = NULL;
	size_t n = 0;

	if (getline(&line, &n, fd) == -1) {
		shell->script = false;
		fclose(fd);
		return (NULL);
	}
	return (line);
}

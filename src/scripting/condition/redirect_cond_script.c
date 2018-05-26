/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Scripting conditions redirection
*/

#include "script.h"

char *condition_management(shell_t *shell, cond_t *cond_line, FILE *fd)
{
	char *line = NULL;
	cond_redir_t cond_array[1] = {{IF, &if_management}};

	for (int i = 0; i < 1 && !line; i += 1) {
		if (cond_line->key == cond_array[i].key)
			line = cond_array[i].redir_cond(shell, cond_line, fd);
	}
	return (line);
}

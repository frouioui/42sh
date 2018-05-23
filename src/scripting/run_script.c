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
	int status = 0;
	static cond_t *cond_line = NULL;

	if (!cond_line)
		if (!(cond_line = init_conditional_line()))
			return (NULL);
	if (getline(&line, &n, fd) == -1) {
		shell->script = false;
		fclose(fd);
		return (NULL);
	}
	if ((status = search_keyword(cond_line, line)) == FAILURE) {
		free_cond_line(cond_line);
		return (NULL);
	}
	if (status == SKIP)
		return (line);
	// contidion mangement
	return (line);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Run script
*/

#include "script.h"

char *is_conditional_line(shell_t *sell, cond_t *cond_line, char *line,
FILE *fd)
{
	int status = 0;

	if (cond_line->end == true) {
		free_cond_line(cond_line);
		cond_line = init_conditional_line();
	}
	if (cond_line->key == EMPTY) {
		if ((status = search_keyword(cond_line, line)) == FAILURE) {
			free_cond_line(cond_line);
			return (NULL);
		}
		if (status == SKIP)
			return (line);
	}
}

char *run_script(shell_t *shell, FILE *fd)
{
	char *line = NULL;
	size_t n = 0;
	int status = 0;
	static cond_t *cond_line = NULL;

	if (!cond_line)
		if (!(cond_line = init_conditional_line()))
			return (NULL);
	if (!(line = get_valid_line(fd, shell)))
		return (NULL);
	line = is_conditional_line(shell, cond_line, line, fd);
	return (line);
}

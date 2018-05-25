/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get valid line in the script
*/

#include "script.h"

static char *check_and_rect_line(char *line)
{
	if (!line)
		return (NULL);
	for (int i = 0; line[i] != '\0'; i += 1) {
		if (line[i] == '#' || line[i] == '\n')
			line[i] = '\0';
	}
	if (!strncmp(line, "#!", 2) || !strcmp(line, "\n") ||
	!strcmp(line, "")) {
		free(line);
		line = NULL;
	}
	return (line);
}

char *get_valid_line(FILE *fd, shell_t *shell)
{
	char *line = NULL;
	size_t n = 0;

	while (!(line = check_and_rect_line(line)))
		if (getline(&line, &n, fd) == -1) {
			shell->script = false;
			fclose(fd);
			return (NULL);
		}
	return (line);
}

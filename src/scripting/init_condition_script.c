/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Conditional structure initialization
*/

#include "script.h"

cond_t *init_conditional_line(void)
{
	cond_t *line = malloc(sizeof(*line));

	if (!line)
		return (NULL);
	line->key = EMPTY;
	line->condition = NULL;
	line->command = NULL;
	line->end = false;
	return (line);
}

void free_cond_line(cond_t *line)
{
	if (!line)
		return;
	if (line->condition)
		free(line->condition);
	if (line->command)
		free(line->command);
	free(line);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** jobs.c
*/

#include "shell.h"

void display_jobs(running_process_t *node)
{
	if (!node)
		return;
	display_process(*node);
	display_jobs(node->next);
}

int jobs_built(shell_t *shell, pipe_t *pipe)
{
	if (!shell || !pipe)
		return (0);
	display_jobs(shell->process);
	return (0);
}

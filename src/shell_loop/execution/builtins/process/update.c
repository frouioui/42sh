/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** update process --> verif the status of process and print it
*/

#include <stdio.h>
#include "process_gestion.h"

void display_process(running_process_t node)
{
	char *tab[NB_STATE] = {RUNNING_S, SUSPEND_S, DONE_S};

	printf("[%d]\t%s\t\t%s\n", node.id, tab[node.state - 1], node.name);
}

void update_running_process(running_process_t **node)
{
	running_process_t *tmp;

	if (!node)
		return;
	if (!*node)
		return;
	if ((*node)->next)
		update_running_process(&(*node)->next);
	if ((*node)->state == DONE) {
		display_process(**node);
		tmp = *node;
		*node = (*node)->next;
		free_a_running_process(&tmp);
	}
}

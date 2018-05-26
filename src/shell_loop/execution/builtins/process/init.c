/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** CORE funtion to use struct running_process_s
*/

#include <stdlib.h>
#include "process_gestion.h"

/*
** ALLOCATE and SET to DEFAULT VALUE running_process_t struct
*/
running_process_t *empty_running_process(void)
{
	running_process_t *node = malloc(sizeof(running_process_t));

	if (!node)
		return NULL;
	node->id = 0;
	node->pid_process = 0;
	node->name = NULL;
	node->state = DONT_SET;
	node->next = NULL;
	return node;
}

/*
** FREE a running process struct
*/
void free_a_running_process(running_process_t **node)
{
	if (!node)
		return;
	if (!*node)
		return;
	if ((*node)->name)
		free((*node)->name);
	free(*node);
	node = NULL;
}

/*
** FREE all running process struct
*/
void free_all_running_process(running_process_t **node)
{
	if (!node)
		return;
	if (!*node)
		return;
	free_all_running_process(&(*node)->next);
	kill((*node)->pid_process, SIGINT);
	free_a_running_process(node);
}

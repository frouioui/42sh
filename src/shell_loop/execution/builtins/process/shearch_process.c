/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Core funtion to use struct running_process_t
*/

#include "shell.h"

running_process_t *get_the_unset_state(running_process_t *node)
{
	for (; node; node = node->next)
		if (node->state == DONT_SET)
			return node;
	return NULL;
}

running_process_t *get_process_from_pid(running_process_t *node, pid_t pid)
{
	for (; node; node = node->next)
		if (node->pid_process == pid)
			return node;
	return NULL;
}

running_process_t *get_process_from_args(running_process_t *node, char **args)
{
	unsigned int id = 0;
	char *arg = (args) ? args[0] : NULL;

	arg = (arg) ? args[1] : NULL;
	if (!arg)
		return node;
	id = atoi(arg);
	if (id == 0)
		return node;
	for (; node; node = node->next)
		if (node->id == id)
			return node;
	return node;
}

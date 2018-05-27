/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Core funtion to use struct running_process_t
*/

#include "shell.h"

unsigned int shearch_better_id(running_process_t *node)
{
	running_process_t *start = node;
	unsigned int id = 1;
	unsigned int match = 1;

	for (id = 1; match; id++) {
		match = 0;
		for (node = start; node; node = node->next)
			match += (id == node->id - 1) ? 1 : 0;
	}
	return (id - 1);
}

bool get_process(struct sigaction *saves[2], pid_t pid, shell_t *shell,
	pipe_t pipe)
{
	unsigned int id = shearch_better_id(shell->process);

	if (init_connection(saves[0], saves[1], do_it_to_child))
		return true;
	if (add_running_process(&shell->process, pid, id,
		pipe.full_instruction))
		return true;
	return false;
}

bool add_running_process(running_process_t **node, pid_t pid_process,
	unsigned int id, char *name)
{
	if (!node)
		return true;
	if (*node)
		return add_running_process(&(*node)->next,
			pid_process, id + 1, name);
	if (!(*node = empty_running_process()))
		return true;
	(*node)->id = id;
	(*node)->pid_process = pid_process;
	(*node)->name = strdup(name);
	return false;
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** update process --> verif the status of process and print it
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void check_sign(int stat)
{
	char *str = NULL;
	int nb = (stat >= 128 ? stat - 128 : stat);

	if (WIFSIGNALED(stat) && nb == SIGFPE) {
		if (WCOREDUMP(stat))
			puts("Floating exception (core dumped)");
		else
			puts("Floating exception");
		return;
	}
	if (WIFSIGNALED(stat)) {
		str = strdup((char *)sys_siglist[nb]);
		WCOREDUMP(stat) ? display_core_dump(str) : printf("%s\n", str);
	} else if (WIFSTOPPED(stat))
		puts("Stopped");
	str != NULL ? free(str) : 0;
}

void display_process(running_process_t node)
{
	char *tabe[NB_STATE] = {RUNNING_S, SUSPEND_S, DONE_S};

	printf("[%d]\t%s\t\t%d\t%s\n", node.id, tabe[node.state - 1],
	node.pid_process, node.name);
}

static void update_data(int wstatus, state_process_t *state)
{
	if (*state == SUSPEND)
		return;
	if (WIFEXITED(wstatus))
		*state = DONE;
}

static void update(running_process_t **node, int safe)
{
	int wstatus = 0;
	int tmp;

	if (!*node)
		return;
	if ((tmp = waitpid((*node)->pid_process, &wstatus, WNOHANG)) == 0)
		return;
	if (tmp == -1 && safe < 8)
		update(node, safe + 1);
	check_sign(wstatus);
	update_data(wstatus, &(*node)->state);
	update_running_process(&(*node)->next);
}

void update_running_process(running_process_t **node)
{
	running_process_t *tmp;

	if (!node)
		return;
	if (!*node)
		return;
	if ((*node)->state == DONE) {
		display_process(**node);
		tmp = *node;
		*node = (*node)->next;
		free_a_running_process(&tmp);
	}
	update(node, 0);
}

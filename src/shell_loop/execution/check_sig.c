/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check if there was any signal in the child process
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mylib.h"

void display_core_dump(char *base)
{
	int i = strlen(base);
	char *str = " (core dumped)";
	char *new = malloc(sizeof(char) * (i + strlen(str) + 2));

	if (new == NULL)
		exit(84);
	strcpy(new, base);
	for (int a = 0; str[a]; a++) {
		new[i] = str[a];
		i++;
	}
	new[i] = '\0';
	puts(new);
}

void check_signal(shell_t *shell, int stat)
{
	char *str = NULL;
	int nb = (stat >= 128 ? stat - 128 : stat);

	if (WIFSIGNALED(stat) && nb == SIGFPE) {
		if (WCOREDUMP(stat))
			puts("Floating exception (core dumped)");
		else
			puts("Floating exception");
		shell->code = nb + 128;
		return;
	}
	if (WIFSIGNALED(stat)) {
		str = strdup((char *)sys_siglist[nb]);
		WCOREDUMP(stat) ? display_core_dump(str) : printf("%s\n", str);
		shell->code = nb + 128;
	} else if (WIFSTOPPED(stat))
		puts("Stopped");
	str != NULL ? free(str) : 0;
}

static void reset_process(running_process_t *ref, running_process_t **process)
{
	running_process_t *tmp;

	if (!process)
		return;
	if (!*process)
		return;
	if (ref == *process) {
		tmp = *process;
		*process = (*process)->next;
		free_a_running_process(&tmp);
		return;
	}
	reset_process(ref, &(*process)->next);
}

static void update_process(shell_t *shell, int stat, bool ampersand)
{
	running_process_t *process = get_the_unset_state(shell->process);

	if (!process)
		return;
	if (ampersand) {
		process->state = RUNNING;
		return;
	}
	if (WIFSIGNALED(stat) || WIFEXITED(stat))
		process->state = DONE;
	if (get_or_set_pid(true, 0, false, false).stop)
		process->state = SUSPEND;
	if (process->state == DONT_SET)
		process->state = RUNNING;
	if (process->state == DONE && !ampersand)
		reset_process(process, &shell->process);
}

void check_sig(shell_t *shell, int stat, bool ampersand)
{
	check_signal(shell, stat);
	update_process(shell, stat, ampersand);
}

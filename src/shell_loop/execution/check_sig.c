/*
** EPITECH PROJECT, 2018
** minishell2
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

static void display_core_dump(char *base)
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

static void check_signal(shell_t *shell, int stat)
{
	int nb = (stat >= 128 ? stat - 128 : stat);

	if (WIFSIGNALED(stat) && nb == SIGFPE) {
		if (WCOREDUMP(stat))
			puts("Floating exception (core dumped)");
		else
			puts("Floating exception");
		shell->code = nb + 128;
		return;
	}
}

static void update_process(shell_t *shell, int stat)
{
	running_process_t *process = get_the_unset_state(shell->process);

	if (!process)
		return;
	if (WIFSIGNALED(stat) || WIFEXITED(stat))
		process->state = DONE;
	if (get_or_set_pid(true, 0, false, false).stop)
		process->state = SUSPEND;
	if (process->state == DONT_SET)
		process->state = RUNNING;
}

void check_sig(shell_t *shell, int stat)
{
	char *str = NULL;
	int nb = (stat >= 128 ? stat - 128 : stat);

	check_signal(shell, stat);
	if (WIFSIGNALED(stat)) {
		str = strdup((char *)sys_siglist[nb]);
		WCOREDUMP(stat) ? display_core_dump(str) : printf("%s\n", str);
		shell->code = nb + 128;
	} else if (WIFSTOPPED(stat))
		puts("Stopped");
	str != NULL ? free(str) : 0;
	update_process(shell, stat);
}

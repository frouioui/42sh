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

void check_sig(shell_t *shell, int stat)
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

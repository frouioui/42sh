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
#include "mylib.h"

static char *display_core_dump(char *base)
{
	int i = my_strlen(base);
	char *str = " (core dumped)\n";
	char *new = malloc(sizeof(char) * (i + my_strlen(str) + 2));

	if (new == NULL)
		exit(84);
	my_strcpy(new, base);
	for (int a = 0; str[a]; a++) {
		new[i] = str[a];
		i++;
	}
	new[i] = '\0';
	my_putstr(new);
}

static void display_sign(char *str)
{
	my_putstr(str);
	my_putchar('\n');
}

void check_sig(shell_t *shell, int stat)
{
	char *str = NULL;
	int nb = (stat >= 128 ? stat - 128 : stat);

	if (WIFSIGNALED(stat) && nb == SIGFPE) {
		if (WCOREDUMP(stat))
			my_putstr("Floating exception (core dumped)\n");
		else
			my_putstr("Floating exception\n");
		shell->code = nb + 128;
		return;
	}
	if (WIFSIGNALED(stat)) {
		str = my_strcpy(NULL, (char *)sys_siglist[nb]);
		WCOREDUMP(stat) ? display_core_dump(str) : display_sign(str);
		shell->code = nb + 128;
	} else if (WIFSTOPPED(stat))
		my_putstr("Stopped\n");
	str != NULL ? free(str) : 0;
}

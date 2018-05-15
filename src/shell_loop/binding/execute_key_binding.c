/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Execution of the binded functions.
*/

#include <stdlib.h>
#include <unistd.h>
#include "execution.h"
#include "shell.h"

static void clear_bind(shell_t *shell)
{
	write(1, "\033c", 2);
}

static void exit_bind(shell_t *shell)
{
	exit_built(shell, NULL);
	write(1, "exit\n", 5);
}

void execute_key_binding(shell_t *shell, binding_t *binding)
{
	redir_binding_t redir[NB_BIND] = {{binding->clear, clear_bind},
	{binding->exit, exit_bind}};

	for (short i = 0; i < NB_BIND; i++) {
		if (redir[i].code == binding->code)
			redir[i].bind(shell);
	}
}

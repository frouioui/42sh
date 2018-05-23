/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Redirect the flow to the right builtin's functions. Returns -1 if error.
*/

#include <unistd.h>
#include <string.h>
#include "instruction.h"
#include "execution.h"

int exec_builtins(shell_t *shell, pipe_t *pipe)
{
	redir_builtins_t redir[NB_BUILTIN] = {{"cd", cd_built},
	{"env", env_built}, {"setenv", setenv_built}, {"exit", exit_built},
	{"unsetenv", unsetenv_built}, {"echo", echo_built},
	{"history", history_built}, {"alias", alias_built},
	{"set", set_built}, {"unset", unset_built}};
	int err = 0;

	for (unsigned short i = 0; i < NB_BUILTIN; i++) {
		if (strcmp(redir[i].name, pipe->args[0]) == 0) {
			builtins_redirect_pipe(shell->bonus, pipe);
			err = redir[i].built(shell, pipe);
			pipe->fd != 1 ? close(pipe->fd) : 0;
			return (err);
		}
	}
	return (-1);
}

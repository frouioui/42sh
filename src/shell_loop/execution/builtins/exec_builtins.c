/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Redirect to the right builtins and exec them, set the error code is error
*/

#include "instruction.h"
#include "execution.h"
#include "mylib.h"

int exec_builtins(shell_t *shell, pipe_t *pipe)
{
	redir_builtins_t redir[NB_BUILTIN] = {{"cd", cd_built},
	{"env", env_built}, {"setenv", setenv_built}, {"exit", exit_built},
	{"unsetenv", unsetenv_built}};

	for (unsigned int i = 0; i < NB_BUILTIN; i++)
		if (my_strcmp(redir[i].name, pipe->args[0]) == 0)
			return (redir[i].built(shell, pipe));
	return (-1);
}

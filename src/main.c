/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Check if args == 1 and init the shell then call the shell function.
*/

#include <stdlib.h>
#include "shell.h"

int main(int argc, char **argv, char **env)
{
	shell_t *shell = NULL;

	if (check_args(argc) == FAILURE)
		return (FAILURE);
	shell = initialisation_shell(argc, argv, env);
	if (shell == NULL)
		return (FAILURE);
	if (shell_loop(shell) == FAILURE)
		return (FAILURE);
	return (destroy_shell(shell));
}

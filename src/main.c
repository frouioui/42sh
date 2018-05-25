/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Check if args == 1 and init the shell then call the shell function.
*/

#include <stdlib.h>
#include "shell.h"
#include "script.h"

int main(int argc, char **argv, char **env)
{
	shell_t *shell = NULL;
	FILE *fd = NULL;

	if (check_args(argc, argv) == FAILURE)
		return (FAILURE);
	shell = initialisation_shell(argc, argv, env);
	if (shell == NULL)
		return (FAILURE);
	fd = open_script(argv[1], shell);
	if (shell_loop(shell, fd) == FAILURE)
		return (FAILURE);
	return (destroy_shell(shell));
}

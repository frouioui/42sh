/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include "shell.h"
#include "echec.h"
#include "mylib.h"

shell_t *initialisation_shell(int argc, char **argv, char **env)
{
	shell_t *shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (NULL);
	if (env != NULL)
		shell->env = copy_environement(env);
	else
		shell->env = set_env_echec_mode();
	if (shell->env == NULL)
		return (NULL);
	shell->bonus = true;
	shell->backup = initialisation_backup(shell->env);
	shell->command_line = NULL;
	shell->code = 0;
	shell->process = NULL;
	shell->state = OK;
	shell->paths = init_paths(shell->env);
	if (shell->backup == NULL)
		return (NULL);
	return (shell);
}

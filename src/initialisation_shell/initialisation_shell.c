/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "shell.h"
#include "echec.h"
#include "mylib.h"

static bool external_init(shell_t *shell)
{
	shell->local = init_local();
	shell->backup = initialisation_backup(shell->env);
	shell->paths = init_paths(shell->env);
	shell->terminal.term = init_terminal(shell);
	shell->binding = init_bindings(shell);
	if (!shell->backup || !shell->paths || !shell->local)
		return (false);
	return (true);
}

shell_t *initialisation_shell(int argc, char **argv, char **env)
{
	shell_t *shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (NULL);
	shell->env = env ? copy_environement(env) : set_env_echec_mode();
	if (shell->env == NULL)
		return (NULL);
	shell->bonus = true;
	shell->script = false;
	shell->command_line = NULL;
	shell->code = 0;
	shell->process = NULL;
	shell->prompt = !isatty(0) ? false : true;
	shell->state = OK;
	if (external_init(shell) == false)
		return (NULL);
	return (shell);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Destroy the shell, and returns the last code value.
*/

#include <stdlib.h>
#include "shell.h"

static void destroy_backup(backup_t *backup)
{
	free(backup->user);
	free(backup->path);
	free(backup->home);
	free(backup->current_pwd);
	free(backup);
}

int destroy_shell(shell_t *shell)
{
	int code = shell->code;

	if (shell->terminal.term == true)
		tcsetattr(0, TCSANOW, &(shell->terminal.old));
	if (shell->local != NULL)
		free_array_string(shell->local);
	destroy_backup(shell->backup);
	free_array_string(shell->env);
	free_array_string(shell->paths);
	if (shell->binding != NULL)
		free(shell->binding);
	free_all_running_process(&shell->process);
	free(shell);
	return (code);
}

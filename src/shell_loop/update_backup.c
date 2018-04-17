/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Update the backup struct with the new values
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"

void update_backup(shell_t *shell)
{
	char *new_pwd = my_get_env(shell->env, "PWD");

	if (new_pwd == NULL)
		return;
	free(shell->backup->current_pwd);
	shell->backup->current_pwd = new_pwd;
}

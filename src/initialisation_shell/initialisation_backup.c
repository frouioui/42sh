/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"
#include "echec.h"

static void set_default_mode_backup(backup_t *backup)
{
	if (backup->path == NULL)
		backup->path = strdup(PATH_ECHEC);
	if (backup->home == NULL)
		backup->home = strdup(PATH_HOME);
	if (backup->user == NULL)
		backup->user = strdup(USER);
	if (backup->current_pwd == NULL)
		backup->current_pwd = strdup(PWD);
}

backup_t *initialisation_backup(char **env)
{
	backup_t *backup = malloc(sizeof(backup_t));

	if (backup == NULL)
		return (NULL);
	backup->home = my_get_env(env, "HOME");
	backup->path = my_get_env(env, "PATH");
	backup->current_pwd = my_get_env(env, "PWD");
	backup->user = my_get_env(env, "USER");
	if (backup->home == NULL || backup->path == NULL ||
		backup->user == NULL || backup->current_pwd == NULL)
		set_default_mode_backup(backup);
	return (backup);
}

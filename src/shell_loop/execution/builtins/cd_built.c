/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Cd builtins functions.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static unsigned int clear_folder_name(char *folder)
{
	unsigned int roll_back = 0;
	unsigned int i = 0;
	unsigned int gap = 0;

	while ((folder[i] == '.' || folder[i] == '/') && folder[i] != '\0') {
		if (folder[i] == '.' && folder[i + 1] == '.' &&
		(folder[i + 2] != '.' || folder[i + 2] == '/'))
			roll_back++;
		i++;
	}
	while (folder[gap] == '.' || folder[gap] == '/')
		gap++;
	i = gap;
	while (folder[i] != '\0') {
		folder[i - gap] = folder[i];
		i++;
	}
	folder[i - gap] = '\0';
	return (roll_back);
}

static void change_env_roll_back(char *env, int roll_back)
{
	unsigned int i = strlen(env);

	while (i > 0 && roll_back > 0) {
		if (env[i] == '/') {
			roll_back--;
			env[i] = '\0';
		}
		i--;
	}
	if (env[4] == '\0') {
		env[4] = '/';
		env[5] = '\0';
	}
}

static char *add_folder_name_env(char *env, char *folder)
{
	char *new = malloc(sizeof(char) * (strlen(env) + strlen(folder) + 2));
	unsigned int i = 0;
	unsigned int j = 0;

	if (new != NULL && folder[0] != '\0') {
		for (i = 0; env[i]; i++) {
			new[j] = env[i];
			j++;
		}
		new[j] = '/';
		j++;
		for (i = 0; folder[i]; i++) {
			new[j] = folder[i];
			j++;
		}
		new[j] = '\0';
		return (new);
	}
	return (env);
}

static char *change_directory(char *folder, char *env, shell_t *shell)
{
	unsigned int roll_back = 0;
	int changed = 0;

	env = cd_special_cases(folder, env, &changed);
	if (env && changed == 0) {
		roll_back = clear_folder_name(folder);
		roll_back > 0 ? change_env_roll_back(env, roll_back) : 0;
		env = add_folder_name_env(env, folder);
	} else if (env == NULL) {
		roll_back = clear_folder_name(folder);
		roll_back > 0 ? change_env_roll_back(
			shell->backup->current_pwd, roll_back) : 0;
		shell->backup->current_pwd = add_folder_name_env(
			shell->backup->current_pwd, folder);
		return (shell->backup->current_pwd);
	}
	return (env);
}

/*
** The char *fl defines the folder's name.
** The pipe_t *p variables defines the current given pipe.
*/
int cd_built(shell_t *shell, pipe_t *p)
{
	unsigned int pos = get_line_env_zero(shell->env, "PWD");
	char *fl = p->args[1] ? strdup(p->args[1]) : NULL;
	char *buf = my_get_env(shell->env, "PWD");

	fl != NULL && fl[0] == '.' ?
	pos = check_rollback_path(shell, p->full_instruction, pos, p->fd) : 0;
	if (fl != NULL && pos != 0 && strcmp(fl, "-") != 0) {
		save_old_pwd(shell->env);
		buf = change_directory(fl, shell->env[pos], shell);
		(chdir(buf + 4) < 0) ? folder_error(shell, errno, fl, p->fd)
			: 0;
		(chdir(buf + 4) != -1) && shell->env[pos] ? shell->env[pos]
			= buf : 0;
	} else if (fl == NULL || strcmp(fl, "-") == 0) {
		fl == NULL ? go_home_cd(shell, p->fd) : 0;
		fl != NULL ? go_back_cd(shell, p->fd) : 0;
		put_new_old_pwd(shell, buf);
	} else
		folder_error(shell, 0, fl, p->fd);
	return (0);
}

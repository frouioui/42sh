/*
** EPITECH PROJECT, 2017
** cd_special_cases.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mylib.h"
#include "shell.h"
#include "execution.h"

static char *get_name_variable(char *env, char *name, int *i)
{
	int a = *i;

	if (name == NULL)
		exit(84);
	for (a = a; env[a] != '=' && env[a]; a++)
		name[a] = env[a];
	*i = a;
	return (name);
}

char *cd_special_cases(char *folder, char *env, int *changed)
{
	char *name = malloc(sizeof(char) * (strlen(env) + strlen(folder) + 1));
	int i = 0;
	int a = 0;

	if (folder[0] != '/' || env == NULL) {
		*changed = 0;
		return (env);
	}
	name = get_name_variable(env, name, &i);
	name[i] = '=';
	i++;
	while (folder[a] != '\0') {
		name[i++] = folder[a++];
		name[i] = '\0';
	}
	*changed = 1;
	env = name;
	return (env);
}

void go_back_cd(shell_t *shell)
{
	char *name = my_get_env(shell->env, "OLDPWD");
	unsigned int a = get_line_env(shell->env, "PWD");
	int i = 0;
	int j = 0;

	name == NULL ? name = malloc(sizeof(char) * 500) : 0;
	for (i = i; shell->env[a] && shell->env[a][i] != '=' &&
		shell->env[a][i]; i++);
	if (shell->env[a] != NULL && chdir(name) != -1) {
		shell->env[a][i] == '=' ? i++ : 0;
		while (name[j]) {
			shell->env[a][i] = name[j];
			i++;
			j++;
		}
		shell->env[a][i] = '\0';
	} else if (shell->env[a] != NULL) {
		shell->env[a][i] == '=' ? i++ : 0;
		folder_error(shell, 0, name);
	}
}

void go_home_cd(shell_t *shell)
{
	char *name = my_get_env(shell->env, "HOME");
	unsigned int a = get_line_env(shell->env, "PWD");
	int i = 0;
	int j = 0;

	name == NULL ? name = strdup(shell->backup->home) : 0;
	for (i = i; shell->env[a] && shell->env[a][i] != '=' &&
		shell->env[a][i]; i++);
	if (shell->env[a] != NULL && chdir(name) != -1) {
		shell->env[a][i] == '=' ? i++ : 0;
		while (name[j])
			shell->env[a][i++] = name[j++];
		shell->env[a][i] = '\0';
	} else if (shell->env[a] != NULL) {
		shell->env[a][i] == '=' ? i++ : 0;
		folder_error(shell, 0, name);
	}
}

unsigned int check_rollback_path(shell_t *shell, char *user, unsigned int pos)
{
	int i = 0;
	int number_dot = 0;

	for (i = i; user[i] && user[i] != ' '; i++);
	for (i = i; user[i] && user[i] == ' '; i++);
	if (user[i] == '.' && user[i + 1] == '.' &&
	user[i + 2] == '.')
		return (0);
	for (i = i; user[i] == '.' || user[i] == '/'; i++) {
		if (user[i] == '.') {
			number_dot++;
		} else if (user[i] == '/' && number_dot == 2) {
			number_dot = 0;
		} else {
			folder_error(shell, 0, user);
			return (0);
		}
	}
	return (pos);
}

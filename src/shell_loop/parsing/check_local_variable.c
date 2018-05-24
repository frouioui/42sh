/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Seek, if the args starts with '$', the environement variable
*/

#include <stdlib.h>
#include <string.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static unsigned int right_pos_arg(char *arg)
{
	unsigned int i = 0;

	for (i = 0; arg[i] && arg[i] == '$'; i++);
	return (i);
}

static char *set_args_variable(char *arg, char **env, int start)
{
	int pos = get_pos_key(arg + right_pos_arg(arg), env);
	unsigned int i = 0;

	if (pos == -1) {
		return (arg);
	}
	for (i = 0; env[pos][i] && env[pos][i] != '\t'; i++);
	if (env[pos][i] == '\0')
		return ("");
	free(arg);
	arg = strdup(env[pos] + i + 1);
	return (arg);
}

static char *check_env_variable_next(char *arg, char **env)
{
	for (int i = 0; arg[i + 1] != '\0'; i++) {
		if (arg[i] == '$')
			arg = set_args_variable(arg, env, i + 1);
	}
	return (arg);
}

void check_local_variable(char **args, char **env)
{
	for (int i = 0; args[i] != NULL; i++) {
		args[i] = check_env_variable_next(args[i], env);
	}
}

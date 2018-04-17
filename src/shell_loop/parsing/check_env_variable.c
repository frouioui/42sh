/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Seek, if the args starts with '$', the environement variable
*/

#include <stdlib.h>
#include "instruction.h"
#include "mylib.h"

static char *set_args_variable(char *arg, char **env)
{
	char *variable = my_get_env(env, arg + 1);

	if (variable != NULL) {
		free(arg);
		arg = my_strcpy(NULL, variable);
		free(variable);
		return (arg);
	} else {
		return (arg);
	}
}

void check_env_variable(char **args, char **env)
{
	for (int i = 0; args[i] != NULL; i++) {
		if (args[i][0] == ENV_VARIABLE_CHAR && args[i][1] != '\0') {
			args[i] = set_args_variable(args[i], env);
		}
	}
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Seek, if the args starts with '$', the environement variable
*/

#include <stdlib.h>
#include <string.h>
#include "instruction.h"
#include "mylib.h"

static char *set_args_variable(char *arg, char **env, int start)
{
	int end = find_separator_env(start + arg) + start;
	char *temp = malloc(sizeof(char) * (end - start + 2));
	int env_int = 0;
	char *result = NULL;

	temp[0] = '\0';
	env_int = find_option_env(env, strncat(temp, arg + start, end - 1));
	if (env_int < 0)
		return (arg);
	result = malloc(strlen(env[env_int]) + 1 + start + 1 + strlen(arg)
		- end + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	if (start != 1)
		result = strncat(result, arg, start - 1);
	result = strcat(result, my_get_env_parse(env, env_int));
	if (arg[end] != '\0')
		result = strcat(result, end+arg);
	return (realloc(result, strlen(result) + 1));
}

static char *check_env_variable_next(char *arg, char **env)
{
	for (int i = 0; arg[i + 1] != '\0'; i++) {
		if (arg[i] == '$')
			arg = set_args_variable(arg, env, i + 1);
	}
	return (arg);
}

void check_env_variable(char **args, char **env)
{
	for (int i = 0; args[i] != NULL; i++) {
		args[i] = check_env_variable_next(args[i], env);
	}
}

/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Seek, if the args starts with '$', the environement variable
*/

#include <stdlib.h>
#include <string.h>
#include "instruction.h"
#include "mylib.h"
/*
static char *set_args_variable(char *arg, char **env)
{
	char *variable = my_get_env(env, arg + 1);

	if (variable != NULL) {
		free(arg);
		arg = strdup(variable);
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
		printf("%s\n", args[i]);
	}
}
*/

static char *set_args_variable(char *arg, char **env, int start)
{
	int end = find_separator_env(start+arg)+start;
	int env_int = find_option_env(env, arg+start);
	char *result = NULL;
	char *temp = NULL;
	char *temp_end = NULL;

	printf("env int %d end %d | arg: %s arg+start: %s end+arg %s\n", env_int, end, arg, start+arg, end+arg);
	if (env_int < 0)
		return (arg);
	result = malloc(strlen(env[env_int])+1+start+1+strlen(arg)-end+1);
	if (start != 1) {
		temp = malloc(sizeof(char) * (start+1));
		strncpy(temp, arg, start-1);
		strcat(result, temp);
	}
	strcat(result, env[env_int]);
	if (arg[end] != '\0') {
		temp_end = end+arg;
		strcat(result, temp_end);
	}
	result = realloc(result, strlen(result));
	printf("OH MEC : %s\n", result);
	return (result);
}

void check_env_variable_next(char *arg, char **env)
{
	for (int i = 0; arg[i+1] != '\0'; i++) {
		if (arg[i] == '$')
			arg = set_args_variable(arg, env, i+1);
	}
}

void check_env_variable(char **args, char **env)
{
	for (int i = 0; args[i] != NULL; i++)
		check_env_variable_next(args[i], env);
}

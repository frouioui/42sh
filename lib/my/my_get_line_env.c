/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Get the line where the target is define int the env
*/

#include <stdlib.h>

static int compare_traget(char *line, char *target)
{
	int i = 0;

	while (line[i] != '=' && line[i] != '\0' && target[i]
			&& line[i] == target[i])
		i++;
	if (line[i] == '=' && target[i] == '\0')
		return (1);
	return (0);
}

unsigned int get_line_env(char **env, char *target)
{
	unsigned int line = 0;

	if (env == NULL)
		return (0);
	while (env[line] != NULL) {
		if (compare_traget(env[line], target) == 0)
			line++;
		else
			return (line);
	}
	return (line);
}

unsigned int get_line_env_zero(char **env, char *target)
{
	unsigned int line = 0;

	if (env == NULL)
		return (0);
	while (env[line] != NULL) {
		if (compare_traget(env[line], target) == 0)
			line++;
		else
			return (line);
	}
	return (line);
}

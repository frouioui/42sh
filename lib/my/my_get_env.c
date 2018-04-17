/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Graph a live in the env, depending on the given keyword
*/

#include <stdlib.h>
#include "mylib.h"

static char *copy_elem(char *env, int cursor)
{
	char *elem = malloc(sizeof(char) * (my_strlen(env + cursor) + 2));
	int i = 0;

	while (env[cursor] != '\0') {
		elem[i] = env[cursor];
		cursor++;
		i++;
	}
	elem[i] = '\0';
	return (elem);
}

char *my_get_env(char **env, char *target)
{
	char *elem = NULL;
	int i = 0;
	int a = 0;

	while (env[i] != NULL) {
		while (env[i][a] == target[a] && target[a] != '\0')
			a++;
		if (target[a] == '\0' && env[i][a] == '=' &&
		env[i][a - 1] == target[a - 1]) {
			elem = copy_elem(env[i], a + 1);
			return (elem);
		} else {
			a = 0;
		}
		i++;
	}
	return (NULL);
}

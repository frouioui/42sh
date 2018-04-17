/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Inits the echec mode shell's environement
*/

#include <stdlib.h>
#include "shell.h"
#include "echec.h"
#include "mylib.h"

char **set_env_echec_mode(void)
{
	char **env = malloc(sizeof(char) * (ENV_SIZE_ECHEC + 1));
	char echec[ENV_SIZE_ECHEC][90] = ENV_ECHEC;

	if (env == NULL)
		return (NULL);
	for (int i = 0; i < ENV_SIZE_ECHEC; i++) {
		env[i] = malloc(sizeof(char) * (my_strlen(echec[i]) + 1));
		if (env[i] == NULL)
			return (NULL);
		env[i] = my_strcpy(env[i], echec[i]);
	}
	return (env);
}

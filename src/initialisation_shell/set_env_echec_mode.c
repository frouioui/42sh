/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Inits the echec mode shell's environement
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "echec.h"

char **set_env_echec_mode(void)
{
	char **env = malloc(sizeof(char) * (ENV_SIZE_ECHEC + 1));
	char echec[ENV_SIZE_ECHEC][90] = ENV_ECHEC;

	if (env == NULL)
		return (NULL);
	for (int i = 0; i < ENV_SIZE_ECHEC; i++) {
		env[i] = malloc(sizeof(char) * (strlen(echec[i]) + 1));
		if (env[i] == NULL)
			return (NULL);
		env[i] = strcpy(env[i], echec[i]);
	}
	return (env);
}

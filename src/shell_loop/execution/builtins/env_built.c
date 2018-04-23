/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Function that display the whole environement
*/

#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"

int env_built(shell_t *shell, pipe_t *pipe)
{
	for (int i = 0; shell->env[i]; i++) {
		write(pipe->fd, shell->env[i], strlen(shell->env[i]));
		write(pipe->fd, "\n", 1);
	}
	return (0);
}

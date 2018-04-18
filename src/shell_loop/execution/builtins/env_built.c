/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Function that display the whole environement
*/

#include <stdio.h>
#include "shell.h"
#include "instruction.h"

int env_built(shell_t *shell, pipe_t *pipe)
{
	for (int i = 0; shell->env[i]; i++)
		puts(shell->env[i]);
	return (0);
}

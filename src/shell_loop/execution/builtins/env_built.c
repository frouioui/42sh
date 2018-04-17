/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Function that display the whole environement
*/

#include "shell.h"
#include "instruction.h"
#include "mylib.h"

int env_built(shell_t *shell, pipe_t *pipe)
{
	for (int i = 0; shell->env[i]; i++) {
		my_putstr(shell->env[i]);
		my_putchar('\n');
	}
	return (0);
}

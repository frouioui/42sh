/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test functions of the history builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

/* crash test */
Test(history_built, display_full_history)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(true, NULL, env);
	shell->command_line = get_command_line(true, "echo a > z", shell->env);
	execute_command(shell, shell->command_line);
	shell->command_line = get_command_line(true, "history", shell->env);
	exec_builtins(shell, shell->command_line->instruction[0]->pipe[0]);
}

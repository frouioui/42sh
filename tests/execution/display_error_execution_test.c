/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the display_error_exec function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "execution.h"
#include "instruction.h"

static shell_t *test_instruction(char *str)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char buf[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(buf[i]));
		env[i] = my_strcpy(env[i], buf[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	shell->command_line = get_command_line(true, str, shell->env, NULL);
	return (shell);
}

/* Crash test cannot verify the output */
Test(display_error_instruction, invalid_pipe)
{
	shell_t *shell = test_instruction("salut| | salut");

	shell->command_line->instruction[0]->valid = false;
	display_error_instruction(shell->command_line->instruction[0]);
}

/* Crash test cannot verify the output */
Test(display_error_instruction, invalid_redirection)
{
	shell_t *shell = test_instruction("salut <> salut");

	cr_redirect_stdout();
	display_error_instruction(shell->command_line->instruction[0]);
}

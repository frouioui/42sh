/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the unsetenv builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "execution.h"

void redirection(void)
{
	cr_redirect_stdout();
}

Test(unsetenv_built, simple_environement_unsetenv_one, .init = redirection)
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
	shell = initialisation_shell(1, NULL, env);
	shell->command_line = get_command_line(false, "unsetenv USER",
		shell->env, NULL);
	unsetenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[0], "PATH=/bin");
	cr_assert_str_eq(shell->env[1], "HOME=/home");
	cr_assert_str_eq(shell->env[2], "PWD=/home/marvin");
}

Test(unsetenv_built, error_management, .init = redirection)
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
	shell = initialisation_shell(1, NULL, env);
	shell->command_line = get_command_line(false, "unsetenv",
		shell->env, NULL);
	unsetenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_eq(shell->code, 1);
}

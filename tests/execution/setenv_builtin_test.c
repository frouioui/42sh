/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Test file of the cd builtins
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

Test(setenv_builtin_1, simple_setenv)
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
	shell->command_line = get_command_line(false, "setenv TOTO",
		shell->env);
	setenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[4], "TOTO=");
	cr_assert_null(shell->env[5]);
}

Test(setenv_builtin_2, simple_setenv_looping)
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
	shell->command_line = get_command_line(false, "setenv TOTO",
		shell->env);
	for (int i = 0; i < 10; i++) {
		setenv_built(shell, shell->command_line->instruction[0]->
			pipe[0]);
		cr_assert_str_eq(shell->env[4], "TOTO=");
		cr_assert_null(shell->env[5]);
	}
}

Test(setenv_builtin_3, simple_setenv_with_value)
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
	shell->command_line = get_command_line(false, "setenv TOTO 123",
		shell->env);
	setenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[4], "TOTO=123");
	cr_assert_null(shell->env[5]);
}

Test(setenv_builtin_4, simple_setenv_update_of_value)
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
	shell->command_line = get_command_line(true, "setenv A 1", shell->env);
	setenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[4], "A=1");
	cr_assert_null(shell->env[5]);
	shell->command_line = get_command_line(true, "setenv A 2", shell->env);
	setenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[4], "A=2");
	cr_assert_null(shell->env[5]);
}

Test(setenv_builtin_5, wrong_command_setenv)
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
	shell->command_line = get_command_line(true, "setenv O=1é",
		shell->env);
	setenv_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_eq(shell->code, 1);
	cr_assert_null(shell->env[4]);
}

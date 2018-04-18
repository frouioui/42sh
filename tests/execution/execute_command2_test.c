/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** test file of the executions functions #2.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"
#include "mylib.h"

Test(execute_command_6, simple_redirection, .timeout = 0.2)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	shell->command_line = get_command_line(false, "echo toto > i",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
	fp = fopen ("i","rw");
	cr_assert_file_contents_eq_str(fp, "toto\n");
}

Test(execute_command_7, simple_and_double_redirection, .timeout = 0.2)
{
	shell_t *sh = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	sh = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	sh->command_line = get_command_line(false, "echo toto > a", sh->env);
	cr_assert_eq(execute_command(sh, sh->command_line), 0);
	sh->command_line = get_command_line(false, "echo ahah >> a", sh->env);
	cr_assert_eq(execute_command(sh, sh->command_line), 0);
	fp = fopen ("a","rw");
	cr_assert_file_contents_eq_str(fp, "toto\nahah\n");
}

Test(execute_command_8, simple_redirection_input, .timeout = 0.2)
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
	cr_redirect_stdout();
	shell->command_line = get_command_line(false, "echo toto > y",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
	shell->command_line = get_command_line(false, "grep test < y",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 1);
}

Test(execute_command_9, simple_redirection_input, .timeout = 0.2)
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
	cr_redirect_stdout();
	shell->command_line = get_command_line(false, "echo toto > u",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
	shell->command_line = get_command_line(false, "grep toto < u",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
}

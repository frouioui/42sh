/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** test file of the executions functions #3.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"
#include "mylib.h"

Test(execute_command_10, simple_pipe, .timeout = 0.2)
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
	shell->command_line = get_command_line(false, "ls | grep M",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
}

Test(execute_command_11, invalid_command_simple_pipe, .timeout = 0.2)
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
	shell->command_line = get_command_line(false, "echo x | exittt",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 1);
	cr_assert_stdout_eq_str("exittt: Command not found.\n");
}

Test(execute_command_12, simple_pipe, .timeout = 0.2)
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
	shell->command_line = get_command_line(false, "echo a | grep a > b",
		shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 0);
	fp = fopen("b","rw");
	cr_assert_file_contents_eq_str(fp, "a\n");
}

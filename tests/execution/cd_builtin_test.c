/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the cd builtins
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

Test(cd_built_1, check_new_pwd)
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
	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(false, "cd ../../", shell->env,
		NULL);
	cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[3], "PWD=/");
}

Test(cd_built_2, check_new_pwd)
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
	shell->command_line = get_command_line(false, "cd /", shell->env,
		NULL);
	cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[3], "PWD=/");
}

Test(cd_built_3, check_new_pwd_with_old_path)
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
	shell->command_line = get_command_line(false, "cd -", shell->env,
		NULL);
	cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[3], "PWD=/home/marvin");
}

Test(cd_built_4, check_new_pwd_home_variable)
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
	shell->command_line = get_command_line(false, "cd", shell->env,
		NULL);
	cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[3], "PWD=/home");
}

Test(cd_built_5, wrong_folder_check_output)
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
	shell->command_line = get_command_line(false, "cd packers/cheez",
		shell->env, NULL);
	cr_redirect_stdout();
	cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->env[3], "PWD=/home/marvin");
	cr_assert_stdout_eq_str("packers/cheez: No such file or directory.\n");
}

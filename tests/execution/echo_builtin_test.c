/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit test on echo builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "execution.h"
#include "shell.h"
#include "mylib.h"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(echo_built, without_opt, .init = redirect_all_std)
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
	shell->command_line = get_command_line(false, "echo toto", shell->env,
		NULL);
	echo_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_stdout_eq_str("toto\n");
}

Test(echo_built, with_opt, .init = redirect_all_std)
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
	shell->command_line = get_command_line(false, "echo -n toto",
	shell->env, NULL);
	echo_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_stdout_eq_str("toto");
}

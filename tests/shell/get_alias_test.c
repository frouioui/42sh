/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the get_alias function and its sub functions.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "alias.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static shell_t *create_env(char *filename)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=.",
		"PWD=/home/marvin"};

	if (env == NULL || pipe == NULL)
		return (NULL);
	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(true, NULL, env);
	if (shell->paths != NULL && shell->paths[0] != NULL)
		shell->paths[0] = strdup(filename);
	return (shell);
}

Test(get_alias, get_simple_full_alias)
{
	shell_t *shell = create_env("alias_test4");
	char *input = NULL;

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias ll ls -l",
		shell->env, NULL);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	input = get_alias(cut_line("ll"), strdup("ll"), "./alias_test4");
	cr_assert_str_eq(input, "ls -l");
}

Test(get_alias, get_simple_incomplete_alias)
{
	shell_t *shell = create_env("alias_test5");
	char *input = NULL;

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias ll",
		shell->env, NULL);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	input = get_alias(cut_line("ll"), strdup("ll"), "./alias_test5");
	cr_assert_str_eq(input, "ll");
}

Test(get_alias, get_simple_no_alias_alias)
{
	shell_t *shell = create_env("alias_test6");
	char *input = NULL;

	if (shell == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	input = get_alias(cut_line("ll"), strdup("ll"), "./alias_test6");
	cr_assert_str_eq(input, "ll");
}

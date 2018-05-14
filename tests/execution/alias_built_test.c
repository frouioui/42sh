/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the alias builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "instruction.h"
#include "execution.h"

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

Test(alias_built, empty_display_alias)
{
	shell_t *shell = create_env("alias_test0");

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias", shell->env);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
}

Test(alias_built, create_one_and_display)
{
	shell_t *shell = create_env("alias_test1");

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias ll ls",
		shell->env);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	shell->command_line = get_command_line(true, "alias", shell->env);
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_stdout_eq_str("ll ls\n");
}

Test(alias_built, complete_command_alias)
{
	shell_t *shell = create_env("alias_test2");

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias ll ls -l",
		shell->env);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	shell->command_line = get_command_line(true, "alias", shell->env);
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_stdout_eq_str("ll ls -l\n");
}

Test(usage_of_alias, should_not_crash_wrong_syntax)
{
	shell_t *shell = create_env("alias_test3");

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "alias to ",
		shell->env);
	if (shell->command_line == NULL)
		cr_assert_fail();
	cr_redirect_stdout();
	alias_built(shell, shell->command_line->instruction[0]->pipe[0]);
	shell->command_line = get_command_line(true, "to", shell->env);
	execute_command(shell, shell->command_line);
}

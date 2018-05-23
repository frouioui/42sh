/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the set builtin
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"

static shell_t *create_env(void)
{
	shell_t *shell = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=.",
		"PWD=/home/marvin"};

	if (env == NULL)
		return (NULL);
	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(true, NULL, env);
	return (shell);
}

Test(set_built, set_one_variable)
{
	shell_t *shell = create_env();

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "set toto=ok",
		shell->env);
	set_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->local[0], "toto\tok");
	cr_assert_null(shell->local[1]);
}

Test(set_built, set_two_variables)
{
	shell_t *shell = create_env();

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "set toto=ok slt=no",
		shell->env);
	set_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->local[0], "toto\tok");
	cr_assert_str_eq(shell->local[1], "slt\tno");
	cr_assert_null(shell->local[2]);
}

Test(set_built, update_one_variables)
{
	shell_t *shell = create_env();

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "set toto=ok toto=no",
		shell->env);
	set_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_str_eq(shell->local[0], "toto\tno");
	cr_assert_null(shell->local[1]);
}

Test(set_built, wrong_syntax)
{
	shell_t *shell = create_env();

	if (shell == NULL)
		cr_assert_fail();
	shell->command_line = get_command_line(true, "set = ",
		shell->env);
	set_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_eq(shell->code, 0);
	cr_assert_null(shell->local[0]);
}

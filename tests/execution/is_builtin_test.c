/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Test file of the is_builtins function.
*/

#include <criterion/criterion.h>
#include "execution.h"

Test(is_builtins_1, valid_builtins)
{
	char cd[] = "cd";
	char env[] = "env";
	char setenv[] = "setenv";
	char exit_b[] = "exit";
	char unsetenv[] = "unsetenv";
	char echo[] = "echo";

	cr_assert_eq(is_builtins(cd), true);
	cr_assert_eq(is_builtins(env), true);
	cr_assert_eq(is_builtins(setenv), true);
	cr_assert_eq(is_builtins(exit_b), true);
	cr_assert_eq(is_builtins(unsetenv), true);
	cr_assert_eq(is_builtins(echo), true);
}

Test(is_builtins_2, invalid_builtins)
{
	cr_assert_eq(is_builtins("toto"), false);
	cr_assert_eq(is_builtins("salut"), false);
	cr_assert_eq(is_builtins(" cd "), false);
	cr_assert_eq(is_builtins("uns etenv"), false);
}

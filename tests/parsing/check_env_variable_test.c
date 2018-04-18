/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Test file of the check_env_variable functions.
*/

#include <criterion/criterion.h>
#include "instruction.h"
#include "mylib.h"

Test(check_env_variable_1, check_1_variable)
{
	char **env = malloc(sizeof(char *) * 2);
	char **args = malloc(sizeof(char *) * 2);

	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	env[1] = my_strcpy(env[1], "TUTU=tata");
	args[0] = my_strcpy(args[0], "/bin/ls");
	args[1] = my_strcpy(args[1], "$HOME");
	check_env_variable(args, env);
	cr_assert_str_eq(args[0], "/bin/ls");
	cr_assert_str_eq(args[1], "/home/gildas");
}

Test(check_env_variable_2, check_2_variables)
{
	char **env = malloc(sizeof(char *) * 2);
	char **args = malloc(sizeof(char *) * 4);

	args[0] = malloc(sizeof(char) * 20);
	args[1] = malloc(sizeof(char) * 20);
	args[2] = malloc(sizeof(char) * 20);
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	env[1] = my_strcpy(env[1], "TUTU=tata");
	args[0] = my_strcpy(args[0], "/bin/ls");
	args[1] = my_strcpy(args[1], "$HOME");
	args[2] = my_strcpy(args[2], "$TUTU");
	args[3] = NULL;
	check_env_variable(args, env);
	cr_assert_str_eq(args[0], "/bin/ls");
	cr_assert_str_eq(args[1], "/home/gildas");
	cr_assert_str_eq(args[2], "tata");
}

Test(check_env_variable_3, check_0_variable)
{
	char **env = malloc(sizeof(char *) * 2);
	char **args = malloc(sizeof(char *) * 4);

	args[0] = malloc(sizeof(char) * 20);
	args[1] = malloc(sizeof(char) * 20);
	args[2] = malloc(sizeof(char) * 20);
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	env[1] = my_strcpy(env[1], "TUTU=tata");
	args[0] = my_strcpy(args[0], "/bin/ls");
	args[1] = my_strcpy(args[1], "$");
	args[2] = my_strcpy(args[2], "$");
	args[3] = NULL;
	check_env_variable(args, env);
	cr_assert_str_eq(args[0], "/bin/ls");
	cr_assert_str_eq(args[1], "$");
	cr_assert_str_eq(args[2], "$");
}

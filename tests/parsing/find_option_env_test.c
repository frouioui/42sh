/*
** EPITECH PROJECT, 2017
** find_option_env_test.c
** File description:
** florian.davasse@epitech.eu
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(find_option_env, bad_env, .timeout = 0.5)
{
	char **env = NULL;

	cr_assert_eq(find_option_env(env, "test"), -1);
}

Test(find_option_env, good_env_bad_str, .timeout = 0.5)
{
	char **env = malloc(sizeof(char *) * 2);

	env[0] = malloc(sizeof(char) * 10);
	env[0] = "coucou";
	env[1] = NULL;
	cr_assert_eq(find_option_env(env, "test"), -2);
}

Test(find_option_env, good_env_good_str, .timeout = 0.5)
{
	char **env = malloc(sizeof(char *) * 2);

	env[0] = malloc(sizeof(char) * 10);
	env[0] = "coucou";
	env[1] = NULL;
}

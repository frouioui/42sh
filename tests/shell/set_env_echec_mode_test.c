/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the set_env_echec_mode function
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "echec.h"

Test(set_env_echec_mode_1, check_value_new_shell)
{
	char **env = set_env_echec_mode();
	char ref[ENV_SIZE_ECHEC][90] = ENV_ECHEC;

	cr_assert_not_null(env);
	for (int i = 0; i < ENV_SIZE_ECHEC; i++) {
		cr_assert_str_eq(env[i], ref[i]);
	}
}

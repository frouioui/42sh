/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Test file of the initialisation_shell functions
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "echec.h"
#include "mylib.h"

Test(initialisation_shell_1, check_value, .timeout = 2)
{
	shell_t *shell = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_assert_not_null(shell);
	cr_assert_str_eq(shell->backup->path, "/bin");
	cr_assert_str_eq(shell->backup->current_pwd, "/home/marvin");
	cr_assert_str_eq(shell->backup->user, "pflorent");
	cr_assert_str_eq(shell->backup->home, "/home");
	cr_assert_str_eq(env[0], "PATH=/bin");
	cr_assert_str_eq(env[1], "USER=pflorent");
	cr_assert_str_eq(env[2], "HOME=/home");
	cr_assert_str_eq(env[3], "PWD=/home/marvin");
}

Test(initialisation_shell_2, check_echec_mode, .timeout = 1)
{
	shell_t *shell = NULL;
	char echec[4][90] = ENV_ECHEC;

	shell = initialisation_shell(1, NULL, NULL);
	cr_assert_str_eq(shell->backup->path, "/usr/local/sbin:/usr/local/"\
		"bin:/usr/sbin:/usr/bin:/sbin:/bin");
	cr_assert_str_eq(shell->backup->current_pwd, "/");
	cr_assert_str_eq(shell->backup->user, "anonyme");
	cr_assert_str_eq(shell->backup->home, "/home");
	cr_assert_str_eq(shell->env[0], echec[0]);
	cr_assert_str_eq(shell->env[1], echec[1]);
	cr_assert_str_eq(shell->env[2], echec[2]);
	cr_assert_str_eq(shell->env[3], echec[3]);
}

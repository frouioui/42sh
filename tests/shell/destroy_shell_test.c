/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test of the destroy_shell function, these tests should not abort
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "shell.h"
#include "mylib.h"

Test(destroy_shell, check_abort, .timeout = 2)
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
	destroy_shell(shell);
}

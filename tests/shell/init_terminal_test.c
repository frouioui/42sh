/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the init terminal function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "shell.h"

Test(init_terminal, no_term_variable, .timeout = 0.5)
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
	cr_assert_eq(shell->term, false);
}

Test(init_terminal, valid_term_variable_not_tty, .timeout = 0.5)
{
	shell_t *shell = NULL;
	char **env = malloc(sizeof(char *) * (6));
	char str[5][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin", "TERM=xterm"};

	for (int i = 0; i < 5; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[5] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_assert_not_null(shell);
	cr_assert_eq(shell->term, false);
}

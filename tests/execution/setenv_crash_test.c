/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Crash test of the setenv builtin (Should not crash this test)
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

Test(setenv_builtin, crash_test_1)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (2));
	char str[2][17] = {"PATH=/bin"};
	char buf[11][16] = {"setenv TOTO", "setenv TITI 1", "setenv PATH 3",
	"setenv VAR 7823", "setenv TOTO 324", "setenv RE 23", "setenv PATH 4",
	"setenv VAR 13", "setenv TITI 3", "setenv TITI 3", "setenv 1 1"};
	char **cmd = malloc(sizeof(char *) * 11);

	for (int i = 0; i < 11; i++)
		cmd[i] = my_strcpy(NULL, buf[i]);
	for (int i = 0; i < 1; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[1] = NULL;
	shell = initialisation_shell(1, NULL, env);
	for (int i = 0; i < 11; i++)
		redirect_loop(shell, cmd[i]);
}

Test(setenv_builtin, crash_test_2)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (2));
	char str[2][17] = {"PATH=/bin"};
	char buf[14][16] = {"setenv A", "setenv B", "setenv C", "setenv 89",
	"setenv D", "setenv Z", "setenv D", "setenv X", "setenv 8", "setenv 4",
	"setenv VAR 13", "setenv TITI 3", "setenv TITI 3", "setenv 1 TOOT"};
	char **cmd = malloc(sizeof(char *) * 14);

	for (int i = 0; i < 14; i++)
		cmd[i] = my_strcpy(NULL, buf[i]);
	for (int i = 0; i < 1; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[1] = NULL;
	shell = initialisation_shell(1, NULL, env);
	for (int i = 0; i < 14; i++)
		redirect_loop(shell, cmd[i]);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the env builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "execution.h"
#include "instruction.h"

Test(env_built, check_output_function)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char buf[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(buf[i]));
		env[i] = my_strcpy(env[i], buf[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	shell->command_line = get_command_line(true, "str", shell->env, NULL);
	env_built(shell, shell->command_line->instruction[0]->pipe[0]);
	cr_assert_stdout_eq_str("PATH=/bin\nUSER=pflorent\nHOME=/home\n"\
	"PWD=/home/marvin\n");
}

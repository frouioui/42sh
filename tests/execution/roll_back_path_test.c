/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the get_execution_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"
#include "mylib.h"

Test(get_execution_filepath, simple_roll_back)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	shell->command_line = get_command_line(false, "../a.out", shell->env);
	cr_assert_eq(execute_command(shell, shell->command_line), 1);
}

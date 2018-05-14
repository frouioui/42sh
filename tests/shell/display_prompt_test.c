/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Check the display of the prompt.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "execution.h"
#include "instruction.h"
#include "mylib.h"

Test(display_prompt, correct_prompt, .timeout = 0.5)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (6));
	char str[5][30] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin", "HOSTNAME=jenk-server"};

	for (int i = 0; i < 5; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[5] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	display_prompt(shell);
}

Test(display_prompt, wrong_prompt, .timeout = 0.5)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[1][17] = {"PATH=/bin"};

	for (int i = 0; i < 1; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[1] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	display_prompt(shell);
}

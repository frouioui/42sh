/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Test file of the cd builtins
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

// Should not SegFault ! No spesific result is expected here
Test(cd_built_6, check_new_pwd, .timeout = 2)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[3][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home"};

	for (int i = 0; i < 3; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[3] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_redirect_stdout();
	shell->command_line = get_command_line(false, "cd ./", shell->env);
	for (int i = 0; i < 10; i++)
		cd_built(shell, shell->command_line->instruction[0]->pipe[0]);
}

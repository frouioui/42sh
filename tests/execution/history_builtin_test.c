/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test functions of the history builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static shell_t *create_env(void)
{
	shell_t *shell = NULL;
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=.",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	shell = initialisation_shell(true, NULL, env);
	return (shell);
}

/* crash test */
Test(history_built, display_full_history)
{
	shell_t *shell = create_env();
	FILE *fp = NULL;

	close(open(shell->paths[1], O_RDONLY | O_TRUNC));
	write_command_history(get_command_line(true, "echo a > z",
		shell->env, NULL), shell->paths);
	shell->command_line = get_command_line(true, "history > buf",
		shell->env, NULL);
	execute_command(shell, shell->command_line);
	fp = fopen("buf", "r");
	cr_assert_file_contents_eq_str(fp, "echo a > z\n");
}

Test(history_built, display_full_history_2)
{
	shell_t *shell = create_env();
	FILE *fp = NULL;

	close(open(shell->paths[1], O_RDONLY | O_TRUNC));
	write_command_history(get_command_line(true, "echo a > z",
		shell->env, NULL), shell->paths);
	write_command_history(get_command_line(true, "vald",
		shell->env, NULL), shell->paths);
	shell->command_line = get_command_line(true, "history > buf2",
		shell->env, NULL);
	execute_command(shell, shell->command_line);
	fp = fopen("buf2", "r");
	cr_assert_file_contents_eq_str(fp, "echo a > z\nvald\n");
}

Test(history_built, display_2)
{
	shell_t *shell = create_env();
	FILE *fp = NULL;

	close(open(shell->paths[1], O_RDONLY | O_TRUNC));
	write_command_history(get_command_line(true, "echo a > z",
		shell->env, NULL), shell->paths);
	write_command_history(get_command_line(true, "vald",
		shell->env, NULL), shell->paths);
	write_command_history(get_command_line(true, "valdgrind ; toto",
		shell->env, NULL), shell->paths);
	shell->command_line = get_command_line(true, "history 2 > buf2",
		shell->env, NULL);
	execute_command(shell, shell->command_line);
	fp = fopen("buf2", "r");
	cr_assert_file_contents_eq_str(fp, "vald\nvaldgrind ; toto\n");
}

Test(history_built, display_too_big)
{
	shell_t *shell = create_env();
	FILE *fp = NULL;

	close(open(shell->paths[1], O_RDONLY | O_TRUNC));
	write_command_history(get_command_line(true, "echo a > z",
		shell->env, NULL), shell->paths);
	write_command_history(get_command_line(true, "vald",
		shell->env, NULL), shell->paths);
	write_command_history(get_command_line(true, "valdgrind ; toto",
		shell->env, NULL), shell->paths);
	shell->command_line = get_command_line(true, "history 24 > buf2",
		shell->env, NULL);
	execute_command(shell, shell->command_line);
	fp = fopen("buf2", "r");
	cr_assert_file_contents_eq_str(fp, "echo a > z\nvald\n"\
		"valdgrind ; toto\n");
}

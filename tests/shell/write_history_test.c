/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test the history writting functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

Test(write_command_history, simple_command_1)
{
	command_line_t *cmd = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	close(open(".history", O_RDWR | O_TRUNC));
	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	cmd = get_command_line(true, "ls -l", env);
	write_command_history(true, cmd);
	fp = fopen (".history","r");
	cr_assert_file_contents_eq_str(fp, "ls -l\n");
}

Test(write_command_history, simple_command_2)
{
	command_line_t *cmd = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	close(open(".history", O_RDWR | O_TRUNC));
	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	cmd = get_command_line(true, "ls -l", env);
	write_command_history(true, cmd);
	cmd = get_command_line(true, "env", env);
	write_command_history(true, cmd);
	fp = fopen (".history","r");
	cr_assert_file_contents_eq_str(fp, "ls -l\nenv\n");
}

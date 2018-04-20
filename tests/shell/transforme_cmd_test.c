/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Test the command transformation function ("hst" builtin)
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

Test(apply_transformation, hst_1)
{
	command_line_t *cmd = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	close(open(".history", O_RDWR | O_TRUNC));
	write_command_history(true, get_command_line(true, "exitt", env));
	fp = fopen (".history","r");
	cr_assert_file_contents_eq_str(fp, "exitt\n");
	cr_assert_str_eq(apply_transformation(true, "hst 1"), "exitt");
	close(open(".history", O_RDWR | O_TRUNC));
}

Test(apply_transformation, hst_2)
{
	command_line_t *cmd = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	close(open(".history", O_RDWR | O_TRUNC));
	write_command_history(true, get_command_line(true, "ls -l", env));
	write_command_history(true, get_command_line(true, "env", env));
	fp = fopen (".history","r");
	cr_assert_file_contents_eq_str(fp, "ls -l\nenv\n");
	cr_assert_str_eq(apply_transformation(true, "hst 2"), "ls -l");
	close(open(".history", O_RDWR | O_TRUNC));
}

Test(apply_transformation, hst_3)
{
	command_line_t *cmd = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};
	FILE *fp;

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	close(open(".history", O_RDWR | O_TRUNC));
	write_command_history(true, get_command_line(true, "find *", env));
	write_command_history(true, get_command_line(true, "env", env));
	write_command_history(true, get_command_line(true, "echo toto", env));
	fp = fopen (".history","r");
	cr_assert_file_contents_eq_str(fp, "find *\nenv\necho toto\n");
	cr_assert_str_eq(apply_transformation(true, "hst 3"), "find *");
	close(open(".history", O_RDWR | O_TRUNC));
}

Test(apply_transformation, wrong_hst_empty_history_and_no_args)
{
	close(open(".history", O_RDWR | O_TRUNC));
	cr_assert_str_eq(apply_transformation(true, "hst"), "hst");
	cr_assert_str_eq(apply_transformation(true, "hst 0"), "hst 0");
	cr_assert_str_eq(apply_transformation(true, "hst 1"), "hst 1");
	cr_assert_str_eq(apply_transformation(true, "hst -4"), "hst -4");
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test functions of the get_input group of functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"
#include "input.h"

Test(get_input, no_term_input)
{
	shell_t *shell = NULL;
	int fd_gnl = open("./gnl_buf", O_RDWR | O_CREAT, 0664);
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	if (fd_gnl == -1)
		cr_assert_fail();
	env[4] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_assert_not_null(shell);
	cr_redirect_stdout();
	write(fd_gnl, "ls", 2);
	lseek(fd_gnl, 0, SEEK_SET);
	cr_assert_str_eq(get_input(shell, 1, fd_gnl), "ls");
	remove("./gnl_buf");
}

Test(get_input, valid_term_input_no_tty)
{
	shell_t *shell = NULL;
	int fd_gnl = open("./gnl_buf", O_RDWR | O_CREAT, 0664);
	char **env = malloc(sizeof(char *) * (6));
	char str[5][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin", "TERM=xterm"};

	for (int i = 0; i < 5; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	if (fd_gnl == -1)
		cr_assert_fail();
	env[5] = NULL;
	shell = initialisation_shell(1, NULL, env);
	cr_assert_not_null(shell);
	cr_redirect_stdout();
	write(fd_gnl, "ls", 2);
	lseek(fd_gnl, 0, SEEK_SET);
	cr_assert_str_eq(get_input(shell, 1, fd_gnl), "ls");
	remove("./gnl_buf");
}

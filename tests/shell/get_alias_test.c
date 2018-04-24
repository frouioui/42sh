/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test get_alias function and all its sub functions.
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "alias.h"
#include "mylib.h"

Test(get_alias, one_alias_in_file)
{
	char **args = malloc(sizeof(char *) * 2);
	char **args2 = NULL;
	char str[] = "ll ls -l\n";
	int fd = open(".alias", O_WRONLY | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	args[0] = strdup("ll");
	args[1] = NULL;
	if (fd != -1) {
		write(fd, str, strlen(str));
		close(fd);
	}
	args2 = get_alias(args);
	cr_assert_not_null(args[0]);
	cr_assert_not_null(args[1]);
	cr_assert_str_eq(args2[0], "ls");
	cr_assert_str_eq(args2[1], "-l");
}

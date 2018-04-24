/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test get_alias_from_file function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "alias.h"

Test(get_alias_from_file, check_array_alias_empty)
{
	char ***alias = NULL;

	close(open(".alias", O_RDWR | O_TRUNC));
	alias = get_alias_from_file();
	cr_assert_not_null(alias);
	cr_assert_not_null(alias[0]);
	cr_assert_not_null(alias[1]);
}

Test(get_alias_from_file, check_array_one_alias)
{
	char ***alias = NULL;
	char str[] = "ll ls -l\n";
	int fd = open(".alias", O_RDWR | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	write(fd, str, strlen(str));
	alias = get_alias_from_file();
	cr_assert_not_null(alias);
	cr_assert_not_null(alias[0]);
	cr_assert_not_null(alias[1]);
	cr_assert_str_eq(alias[0][0], "ll");
	cr_assert_str_eq(alias[1][0], "ls -l");
	close(fd);
}

Test(get_alias_from_file, check_array_two_alias)
{
	char ***alias = NULL;
	char str[] = "ll ls -l\necho echo -n\n";
	int fd = open(".alias", O_RDWR | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	write(fd, str, strlen(str));
	alias = get_alias_from_file();
	cr_assert_not_null(alias);
	cr_assert_not_null(alias[0]);
	cr_assert_not_null(alias[1]);
	cr_assert_str_eq(alias[0][0], "ll");
	cr_assert_str_eq(alias[1][0], "ls -l");
	cr_assert_str_eq(alias[0][1], "echo");
	cr_assert_str_eq(alias[1][1], "echo -n");
	close(fd);
}

Test(get_alias_from_file, check_array_three_alias)
{
	char ***alias = NULL;
	char str[] = "ll ls -l\necho  echo -n\nsetenv   setenv toto\n";
	int fd = open(".alias", O_RDWR | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	write(fd, str, strlen(str));
	alias = get_alias_from_file();
	cr_assert_not_null(alias);
	cr_assert_not_null(alias[0]);
	cr_assert_not_null(alias[1]);
	cr_assert_str_eq(alias[0][0], "ll");
	cr_assert_str_eq(alias[1][0], "ls -l");
	cr_assert_str_eq(alias[0][1], "echo");
	cr_assert_str_eq(alias[1][1], "echo -n");
	cr_assert_str_eq(alias[0][2], "setenv");
	cr_assert_str_eq(alias[1][2], "setenv toto");
	close(fd);
}

Test(get_alias_from_file, check_array_pasring_alias)
{
	char ***alias = NULL;
	char str[] = "ll\tls -l\n \t echo    echo -n\n";
	int fd = open(".alias", O_RDWR | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	write(fd, str, strlen(str));
	alias = get_alias_from_file();
	cr_assert_not_null(alias);
	cr_assert_not_null(alias[0]);
	cr_assert_not_null(alias[1]);
	cr_assert_str_eq(alias[0][0], "ll");
	cr_assert_str_eq(alias[1][0], "ls -l");
	cr_assert_str_eq(alias[0][1], "echo");
	cr_assert_str_eq(alias[1][1], "echo -n");
	close(fd);
}

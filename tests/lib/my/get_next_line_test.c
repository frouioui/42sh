/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the GNL
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mylib.h"

Test(get_next_line_1, test_small_file)
{
	int fd = open("./tests/lib/my/test_gnl_1", O_RDONLY);
	char arr[5][20] = {"salut", "comment", "ca va", "ici", "okay\tokay"};

	if (fd != 1) {
		for (int line = 0; line < 5; line++) {
			cr_assert_str_eq(get_next_line(fd), arr[line]);
		}
	}
}

Test(get_next_line_2, test_small_file)
{
	int fd = open("./tests/lib/my/test_gnl_2", O_RDONLY);
	char arr[2][20] = {"ls", "env"};

	if (fd != 1) {
		for (int line = 0; line < 2; line++) {
			cr_assert_str_eq(get_next_line(fd), arr[line]);
		}
	}
}

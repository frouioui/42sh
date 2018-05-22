/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the copy_environement function
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "mylib.h"

Test(copy_environement_1, simple_environement)
{
	char **copy = NULL;
	char **env = malloc(sizeof(char *) * (4));
	char str[3][10] = {"PATH=/bin", "TERM=/", "TOTO=toto"};

	for (int i = 0; i < 3; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[3] = NULL;
	copy = copy_environement(env);
	cr_assert_str_eq(copy[0], "PATH=/bin");
	cr_assert_str_eq(copy[1], "TERM=/");
	cr_assert_str_eq(copy[2], "TOTO=toto");
}

Test(copy_environement_2, bigger_environement)
{
	char **copy = NULL;
	char **env = malloc(sizeof(char *) * (10));
	char str[10][10] = {"PATH=/bin", "TERM=/", "TOTO=toto",
	"PATH=/bin", "TERM=/", "TOTO=toto", "PATH=/bin", "TERM=/", "TOTO=toto",
	"PATH=/bin"};

	for (int i = 0; i < 10; i++)
		env[i] = my_strcpy(NULL, str[i]);
	copy = copy_environement(env);
	cr_assert_str_eq(copy[0], "PATH=/bin");
	cr_assert_str_eq(copy[1], "TERM=/");
	cr_assert_str_eq(copy[2], "TOTO=toto");
	cr_assert_str_eq(copy[3], "PATH=/bin");
	cr_assert_str_eq(copy[4], "TERM=/");
	cr_assert_str_eq(copy[5], "TOTO=toto");
	cr_assert_str_eq(copy[6], "PATH=/bin");
	cr_assert_str_eq(copy[7], "TERM=/");
	cr_assert_str_eq(copy[8], "TOTO=toto");
	cr_assert_str_eq(copy[9], "PATH=/bin");
}

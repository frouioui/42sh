/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the check_args function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"

Test(check_args_1, valid_args)
{
	cr_assert_eq(check_args(1), SUCCESS);
}

Test(check_args_2, not_valid_args)
{
	cr_redirect_stdout();
	cr_assert_eq(check_args(8), FAILURE);
	cr_assert_stdout_eq_str("You must give 0 arguments to the program.\n");
}

Test(check_args_3, negative_number_args)
{
	cr_redirect_stdout();
	cr_assert_eq(check_args(0), FAILURE);
	cr_assert_stdout_eq_str("You must give 0 arguments to the program.\n");
}

Test(check_args_4, valid_args)
{
	cr_assert_eq(check_args(2), SUCCESS);
}

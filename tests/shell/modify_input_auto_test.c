/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the cut_last_input and restore_input_autocompletion functions
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

Test(modify_input_string, cut_last_input)
{
	char *input = strdup("cd te");
	char *new = cut_last_input(input);

	cr_assert_not_null(input);
	cr_assert_not_null(new);
	cr_assert_str_eq(input, "cd ");
	cr_assert_str_eq(new, "te");
}

Test(modify_input_string, restore_input_after)
{
	char *input = strdup("cd ");
	char *new = strdup("tests");
	char *new_input = restore_input_autocompletion(input, new);

	cr_assert_str_eq(new_input, "cd tests");
}

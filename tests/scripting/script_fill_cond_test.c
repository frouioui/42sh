/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on condition structure filling
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_fill_cond, ok)
{
	cond_t *cond = init_conditional_line();
	char **words_array = cut_line("if ($1 == $2) then");
	bool status = false;

	cond->key = IF;
	status = fill_cond(cond, "if ($1 == $2) then", words_array);
	cr_assert_eq(status, true);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
	free_array_string(words_array);
}

Test(script_fill_cond, ko_brackets)
{
	cond_t *cond = init_conditional_line();
	char **words_array = cut_line("if $1 == $2 echo toto");
	bool status = false;

	cond->key = IF;
	status = fill_cond(cond, "if $1 == $2 echo toto", words_array);
	cr_assert_eq(status, false);
	free_cond_line(cond);
	free_array_string(words_array);
}

Test(script_fill_cond, ok_simple_if)
{
	cond_t *cond = init_conditional_line();
	char **words_array = cut_line("if ($1 == $2) echo toto");
	bool status = false;

	cond->key = IF;
	status = fill_cond(cond, "if ($1 == $2) echo toto", words_array);
	cr_assert_eq(status, true);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_str_eq(cond->command, " echo toto");
	cr_assert_eq(cond->end, true);
	free_cond_line(cond);
	free_array_string(words_array);
}

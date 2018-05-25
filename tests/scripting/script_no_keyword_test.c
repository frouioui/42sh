/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on keyword identification
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_no_keyword, ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "echo toto");

	cr_assert_eq(status, SKIP);
	cr_assert_eq(cond->key, EMPTY);
	cr_assert_eq(cond->condition, NULL);
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on keyword identification
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_other_keyword, while_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "while (&toto < 10)");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, WHILE);
	cr_assert_str_eq(cond->condition, "&toto < 10");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

Test(script_other_keyword, while_ko)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "while (&toto < 10) echo toto");

	cr_assert_eq(status, FAILURE);
	cr_assert_eq(cond->key, WHILE);
	cr_assert_str_eq(cond->condition, "&toto < 10");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

Test(script_other_keyword, foreach_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "foreach (&toto < 10)");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, FOREACH);
	cr_assert_str_eq(cond->condition, "&toto < 10");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

Test(script_other_keyword, where_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "where (&toto < 10)");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, WHERE);
	cr_assert_str_eq(cond->condition, "&toto < 10");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

Test(script_other_keyword, which_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "which (&toto < 10)");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, WHICH);
	cr_assert_str_eq(cond->condition, "&toto < 10");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

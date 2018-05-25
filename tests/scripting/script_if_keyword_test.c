/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on keyword identification
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_keyword, if_then_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "if ($1 == $2) then");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, IF);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

Test(script_keyword, if_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "if ($1 == $2) echo toto");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, IF);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_str_eq(cond->command, " echo toto");
	cr_assert_eq(cond->end, true);
	free_cond_line(cond);
}

Test(script_keyword, elseif_ko)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "else if ($1 == $2)");

	cr_assert_eq(status, FAILURE);
	cr_assert_eq(cond->key, ELSIF);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_eq(cond->command, NULL);
	cr_assert_eq(cond->end, true);
	free_cond_line(cond);
}

Test(script_keyword, elseif_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "else if ($1 == $2) set a = 2");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, ELSIF);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_str_eq(cond->command, " set a = 2");
	cr_assert_eq(cond->end, true);
	free_cond_line(cond);
}

Test(script_keyword, else_ok)
{
	cond_t *cond = init_conditional_line();
	int status = search_keyword(cond, "else ($1 == $2) set a = 3");

	cr_assert_eq(status, SUCCESS);
	cr_assert_eq(cond->key, ELSE);
	cr_assert_str_eq(cond->condition, "$1 == $2");
	cr_assert_str_eq(cond->command, " set a = 3");
	cr_assert_eq(cond->end, false);
	free_cond_line(cond);
}

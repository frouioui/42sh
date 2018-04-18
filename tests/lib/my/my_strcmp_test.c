/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <criterion/criterion.h>
#include "mylib.h"

Test(my_strcmp_1, simple_same_string)
{
	int result = my_strcmp("hey", "hey");

	cr_assert_eq(result, 0);
}

Test(my_strcmp_1, simple_wrong_string)
{
	int result = my_strcmp("hey", "hey guys");

	cr_assert_eq(result, 1);
}

Test(my_strcmp_1, simple_same_long_string)
{
	int result = my_strcmp("hey guys how you?", "hey guys how you?");

	cr_assert_eq(result, 0);
}

Test(my_strcmp_1, empty_string)
{
	int result = my_strcmp("", "");

	cr_assert_eq(result, 0);
}

Test(my_strcmp_1, wrong_empty_string)
{
	int result = my_strcmp("", " ");

	cr_assert_eq(result, 1);
}

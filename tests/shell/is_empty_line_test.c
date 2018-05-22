/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test function of the is_empty_input function
*/

#include <criterion/criterion.h>
#include "instruction.h"

Test(is_empty_input, empty_input)
{
	cr_assert_eq(is_empty_input("      \t  "), false);
	cr_assert_eq(is_empty_input("     "), false);
	cr_assert_eq(is_empty_input("\t\t\t\t\t"), false);
}

Test(is_empty_input, not_empty_input)
{
	cr_assert_eq(is_empty_input("ls -l"), true);
	cr_assert_eq(is_empty_input("echo toto | pipe"), true);
	cr_assert_eq(is_empty_input("    toto \t "), true);
}

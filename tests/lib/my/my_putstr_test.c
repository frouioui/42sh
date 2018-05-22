/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Tets file of putstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"

Test(my_putchar, simple_char)
{
	cr_redirect_stdout();
	my_putchar('c');
	cr_assert_stdout_eq_str("c");
}

Test(my_putstr, simple_string)
{
	cr_redirect_stdout();
	my_putstr("Hey guys!");
	cr_assert_stdout_eq_str("Hey guys!");
}

Test(my_putstr, longer_string)
{
	cr_redirect_stdout();
	my_putstr("Hey guys, how are you today ???????????\nhi");
	cr_assert_stdout_eq_str("Hey guys, how are you today ???????????\nhi");
}

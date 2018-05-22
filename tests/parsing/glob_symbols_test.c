/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on glob symbols
*/

#include <criterion/criterion.h>
#include "globbing.h"

Test(glob_symbol, match)
{
	cr_assert_eq(search_glob_symbols("oteztze*s"), true);
	cr_assert_eq(search_glob_symbols("?"), true);
	cr_assert_eq(search_glob_symbols("[toto]"), true);
	cr_assert_eq(search_glob_symbols("toto"), false);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on script file
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_name, name_ok)
{
	cr_assert_eq(check_script_name("./script_test.sh"), true);
}

Test(script_name, name_ko)
{
	cr_assert_eq(check_script_name("toto"), false);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test the alias file writting function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "alias.h"

Test(write_alias_test, simple_alias)
{
	char *alias[] = "ll ls -l";

	write_new_alias(alias);
}

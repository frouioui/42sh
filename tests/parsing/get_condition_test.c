/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test the get_condition function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_condition, NO_condition)
{
	instruction_t *instruction = new_instruction("ls ; toto");

	get_condition(instruction, "; toto");
	cr_assert_eq(instruction->condition, NO);
}

Test(get_condition, OR_condition)
{
	instruction_t *instruction = new_instruction("ls || toto");

	get_condition(instruction, "|| toto");
	cr_assert_eq(instruction->condition, OR);
}

Test(get_condition, AND_condition)
{
	instruction_t *instruction = new_instruction("ls && toto");

	get_condition(instruction, "&& toto");
	cr_assert_eq(instruction->condition, AND);
}

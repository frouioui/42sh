/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Test file of the get_number_instruction function
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_number_instruction_1, 1_instruction, .timeout = 0.5)
{
	cr_assert_eq(get_number_instruction("salut"), 1);
	cr_assert_eq(get_number_instruction("this is a test"), 1);
	cr_assert_eq(get_number_instruction("just one instruction"), 1);
	cr_assert_eq(get_number_instruction("/bin/ls ;"), 1);
}

Test(get_number_instruction_2, 2_instructions, .timeout = 0.5)
{
	cr_assert_eq(get_number_instruction("ls ; cat toto"), 2);
	cr_assert_eq(get_number_instruction("/bin/ls ;;; grep toto"), 2);
	cr_assert_eq(get_number_instruction("./a.out ; cat report"), 2);
}

Test(get_number_instruction_3, 3_instructions, .timeout = 0.5)
{
	cr_assert_eq(get_number_instruction("ls ; cat toto ;; grep tt ;"), 3);
	cr_assert_eq(get_number_instruction("/bin/ls ; ; grep toto ;ls "), 3);
	cr_assert_eq(get_number_instruction("gitkraken ; cat report :; t"), 3);
}

Test(get_number_instruction_4, and_condition_instructions, .timeout = 0.5)
{
	cr_assert_eq(get_number_instruction("ls && grep tt && cat t & "), 3);
	cr_assert_eq(get_number_instruction("/bin/ls & & tto  "), 1);
	cr_assert_eq(get_number_instruction("/bin/ls & tto  "), 1);
	cr_assert_eq(get_number_instruction("ls && grep tt | cat toto"), 2);
	cr_assert_eq(get_number_instruction("/bin/ls && grep toto  "), 2);
	cr_assert_eq(get_number_instruction("gitkraken && cat ret && t"), 3);
}

Test(get_number_instruction_4, or_condition_instructions, .timeout = 0.5)
{
	cr_assert_eq(get_number_instruction("ls || grep tt "), 2);
	cr_assert_eq(get_number_instruction("/bin/ls || grep toto  "), 2);
	cr_assert_eq(get_number_instruction("gitkraken || cat ret | t"), 2);
	cr_assert_eq(get_number_instruction("ls ||| grep tt "), 2);
	cr_assert_eq(get_number_instruction("/bin/ls | grep toto  "), 1);
}

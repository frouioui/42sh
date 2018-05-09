/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the exit builtin
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

Test(exit_builtin, check_exit_code_equal_one)
{
	shell_t *shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		cr_assert_fail();

	shell->state = 0;
	exit_built(shell, NULL);
	cr_assert_eq(shell->state, 1);
}

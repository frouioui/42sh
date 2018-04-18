/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Test file of the analyse_redirect functions
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(analyse_redirect_6, check_value_invalid_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "./my_segfault    \t< >\t     toto.txt  \t\t\t        ";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, false);
	cr_assert_eq(pipe->type_redirect, EMPTY_REDIR);
	cr_assert_eq(pipe->error, INVALID_REDIRECT_NAME);
	cr_assert_eq(pipe->redirect, false);
}

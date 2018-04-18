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

Test(analyse_redirect_1, check_value_1_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "ls > toto.txt";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, true);
	cr_assert_eq(pipe->type_redirect, STDOUT_SIMPLE);
	cr_assert_eq(pipe->error, EMPTY_ERR);
	cr_assert_eq(pipe->redirect, true);
}

Test(analyse_redirect_2, check_value_2_invalid_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "/bin/grep > toto.txt >   ";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, false);
	cr_assert_eq(pipe->type_redirect, EMPTY_REDIR);
	cr_assert_eq(pipe->error, AMBIGUOUS_REDIRECT);
	cr_assert_eq(pipe->redirect, false);
}

Test(analyse_redirect_3, check_value_double_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "/bin/grep   \t  >> toto.txt    ";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, true);
	cr_assert_eq(pipe->type_redirect, STDOUT_DOUBLE);
	cr_assert_eq(pipe->error, EMPTY_ERR);
	cr_assert_eq(pipe->redirect, true);
}

Test(analyse_redirect_4, check_value_double_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "/bin/grep   \t  <<\t toto.txt    ";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, true);
	cr_assert_eq(pipe->type_redirect, STDIN_DOUBLE);
	cr_assert_eq(pipe->error, EMPTY_ERR);
	cr_assert_eq(pipe->redirect, true);
}

Test(analyse_redirect_5, check_value_double_redirect)
{
	pipe_t *pipe = malloc(sizeof(pipe_t));
	char inst[] = "./my_segfault    \t<\t     toto.txt  \t\t\t        ";

	pipe->full_instruction = my_strcpy(pipe->full_instruction, inst);
	pipe->valid = true;
	pipe->args = NULL;
	pipe->redirect = false;
	pipe->error = EMPTY_ERR;
	pipe->type_redirect = EMPTY_REDIR;
	analyse_redirect(false, pipe);
	cr_assert_eq(pipe->valid, true);
	cr_assert_eq(pipe->type_redirect, STDIN_SIMPLE);
	cr_assert_eq(pipe->error, EMPTY_ERR);
	cr_assert_eq(pipe->redirect, true);
}

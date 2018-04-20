/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Chech the whole get_command_line partion.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_command_line_1, test_simple_valid_command)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls ; cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 2);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->number_of_pipe, 1);
	cr_assert_str_eq(command->instruction[0]->full_instruction, inst[0]);
	cr_assert_eq(command->instruction[0]->valid, true);
	cr_assert_eq(command->instruction[1]->number_of_pipe, 1);
	cr_assert_str_eq(command->instruction[1]->full_instruction, inst[1]);
	cr_assert_eq(command->instruction[1]->valid, true);
}

Test(get_command_line_1_2, test_simple_valid_command)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls ; cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_str_eq(command->instruction[0]->pipe[0]->full_instruction,
		inst[0]);
	cr_assert_str_eq(command->instruction[0]->pipe[0]->args[0], inst[0]);
	cr_assert_null(command->instruction[0]->pipe[0]->args[1]);
	cr_assert_eq(command->instruction[0]->pipe[0]->redirect, false);
	cr_assert_str_eq(command->instruction[1]->pipe[0]->full_instruction,
		inst[1]);
	cr_assert_str_eq(command->instruction[1]->pipe[0]->args[0], "cat");
	cr_assert_str_eq(command->instruction[1]->pipe[0]->args[1], "toto");
	cr_assert_null(command->instruction[1]->pipe[0]->args[2]);
	cr_assert_eq(command->instruction[1]->pipe[0]->redirect, false);
}

Test(get_command_line_2, test_pipe_valid_command)
{
	char inst[2][15] = {"/bin/ls | grep", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls | grep ; cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 2);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->number_of_pipe, 2);
	cr_assert_str_eq(command->instruction[0]->full_instruction, inst[0]);
	cr_assert_eq(command->instruction[0]->valid, true);
	cr_assert_eq(command->instruction[1]->number_of_pipe, 1);
	cr_assert_str_eq(command->instruction[1]->full_instruction, inst[1]);
	cr_assert_eq(command->instruction[1]->valid, true);
}

Test(get_command_line_2, test_pipe_not_valid_command)
{
	char inst[2][30] = {"/bin/ls | | grep", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	cr_redirect_stdout();
	user_input = my_strcpy(user_input, "/bin/ls | | grep ; cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 2);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, false);
	cr_assert_eq(command->instruction[0]->number_of_pipe, 0);
	cr_assert_str_eq(command->instruction[0]->full_instruction, inst[0]);
	cr_assert_eq(command->instruction[0]->valid, false);
	cr_assert_eq(command->instruction[1]->number_of_pipe, 0);
}

Test(get_command_line_3, test_pipe_redirect_valid_command)
{
	char inst[2][30] = {"/bin/ls $HOME", "cat toto > salut"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls $HOME ; cat toto > salut");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->number_of_pipe, 1);
	cr_assert_eq(command->instruction[1]->number_of_pipe, 1);
	cr_assert_str_eq(command->instruction[0]->full_instruction, inst[0]);
	cr_assert_str_eq(command->instruction[1]->full_instruction, inst[1]);
	cr_assert_eq(command->instruction[0]->valid, true);
	cr_assert_eq(command->instruction[1]->valid, true);
	cr_assert_eq(command->instruction[0]->pipe[0]->valid, true);
	cr_assert_eq(command->instruction[1]->pipe[0]->valid, true);
	cr_assert_str_eq(command->instruction[0]->pipe[0]->args[1], *env + 5);
	cr_assert_eq(command->instruction[0]->pipe[0]->redirect, false);
	cr_assert_eq(command->instruction[1]->pipe[0]->redirect, true);
}

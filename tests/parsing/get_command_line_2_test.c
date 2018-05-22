/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Chech the whole get_command_line partion.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_command_line_5, and_condition_instruction_easy)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls && cat toto");
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

Test(get_command_line_6, or_condition_instruction_easy)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls || cat toto");
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

Test(get_command_line_7, and_condition_instruction_check_condition)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls&&cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 2);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->condition, AND);
	cr_assert_eq(command->instruction[1]->condition, NO);
}

Test(get_command_line_8, or_and_condition_instruction_check_condition)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls || cat toto && toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 3);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->condition, OR);
	cr_assert_eq(command->instruction[1]->condition, AND);
}

Test(get_command_line_9, or_condition_instruction_check_condition)
{
	char inst[2][15] = {"/bin/ls", "cat toto"};
	char *user_input = NULL;
	char **env = malloc(sizeof(char) * 1);
	command_line_t *command = NULL;

	user_input = my_strcpy(user_input, "/bin/ls||cat toto");
	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	command = get_command_line(false, user_input, env);
	cr_assert_not_null(command);
	cr_assert_eq(command->number_instruction, 2);
	cr_assert_not_null(command->instruction);
	cr_assert_not_null(command->instruction[0]);
	cr_assert_not_null(command->instruction[1]);
	cr_assert_eq(command->valid, true);
	cr_assert_eq(command->instruction[0]->condition, OR);
	cr_assert_eq(command->instruction[1]->condition, NO);
}

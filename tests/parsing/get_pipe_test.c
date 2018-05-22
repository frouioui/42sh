/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the get_pipe_number functions
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_pipe_1, 1_pipe_value, .timeout = 0.2)
{
	instruction_t *inst = malloc(sizeof(instruction_t));
	pipe_t **pipe = NULL;
	char str[] = "ls -l";
	char **env = malloc(sizeof(char *));

	env[0] = my_strcpy(env[0], "TOTO=/bin");
	inst->full_instruction = my_strcpy(inst->full_instruction, str);
	inst->number_of_pipe = 1;
	inst->actual_pipe = 0;
	pipe = get_pipe(false, inst, env);
	cr_assert_not_null(pipe);
	cr_assert_str_eq(pipe[0]->full_instruction, "ls -l");
	cr_assert_str_eq(pipe[0]->args[0], "ls");
	cr_assert_str_eq(pipe[0]->args[1], "-l");
}

Test(get_pipe_1, 2_pipes_value, .timeout = 0.2)
{
	instruction_t *inst = malloc(sizeof(instruction_t));
	pipe_t **pipe = NULL;
	char str[] = "ls -l | grep \"tty\"";
	char **env = malloc(sizeof(char *));

	env[0] = my_strcpy(env[0], "TOTO=/bin");
	inst->full_instruction = my_strcpy(inst->full_instruction, str);
	inst->number_of_pipe = 2;
	inst->actual_pipe = 0;
	pipe = get_pipe(false, inst, env);
	cr_assert_not_null(pipe);
	cr_assert_not_null(pipe[0]);
	cr_assert_not_null(pipe[1]);
	cr_assert_str_eq(pipe[0]->full_instruction, "ls -l");
	cr_assert_str_eq(pipe[0]->args[0], "ls");
	cr_assert_str_eq(pipe[0]->args[1], "-l");
	cr_assert_str_eq(pipe[1]->full_instruction, "grep \"tty\"");
	cr_assert_str_eq(pipe[1]->args[0], "grep");
	cr_assert_str_eq(pipe[1]->args[1], "\"tty\"");
}

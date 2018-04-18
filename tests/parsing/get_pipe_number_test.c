/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Test file of the get_pipe_number functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

Test(get_pipe_number_1, 1_pipe, .timeout = 0.2)
{
	instruction_t **inst = malloc(sizeof(instruction_t *) * 4);
	char str[4][20] = {"ls", "grep \"tty\"", "/bin/cat main.cpp",
		"/bin/ls"};

	for (int i = 0; i < 4; i++) {
		inst[i] = malloc(sizeof(instruction_t));
		inst[i]->full_instruction =
		my_strcpy(inst[i]->full_instruction, str[i]);
		inst[i]->valid = true;
		cr_assert_eq(get_pipe_number(inst[i]), 1);
	}
}

Test(get_pipe_number_2, 2_pipe, .timeout = 0.2)
{
	instruction_t **inst = malloc(sizeof(instruction_t *) * 3);
	char str[3][50] = {"ls | grep \"toto\"", "ls -l|salut",
		"./a.out | cat report"};

	for (int i = 0; i < 3; i++) {
		inst[i] = malloc(sizeof(instruction_t));
		inst[i]->full_instruction =
		my_strcpy(inst[i]->full_instruction, str[i]);
		inst[i]->valid = true;
		cr_assert_eq(get_pipe_number(inst[i]), 2);
	}
}

Test(get_pipe_number_3, 3_pipe, .timeout = 0.2)
{
	instruction_t **inst = malloc(sizeof(instruction_t *) * 2);
	char str[2][60] = {"ls | cat toto | grep tt",
		"grep \"tty\" | salut | salut"};

	for (int i = 0; i < 2; i++) {
		inst[i] = malloc(sizeof(instruction_t));
		inst[i]->full_instruction =
		my_strcpy(inst[i]->full_instruction, str[i]);
		inst[i]->valid = true;
		cr_assert_eq(get_pipe_number(inst[i]), 3);
	}
}

Test(get_pipe_number_4, 4_pipe, .timeout = 0.2)
{
	instruction_t **inst = malloc(sizeof(instruction_t *) * 2);
	char str[2][60] = {"ls | cat toto | grep tt | dif toto toto slnine",
		"grep \"tty\" | salut | salut |   cat eldo"};

	for (int i = 0; i < 2; i++) {
		inst[i] = malloc(sizeof(instruction_t));
		inst[i]->full_instruction =
		my_strcpy(inst[i]->full_instruction, str[i]);
		inst[i]->valid = true;
		cr_assert_eq(get_pipe_number(inst[i]), 4);
	}
}

Test(get_pipe_number_5, wrong_pipe, .timeout = 0.2)
{
	instruction_t **inst = malloc(sizeof(instruction_t *) * 2);
	char str[2][60] = {"ls |  | cat toto | grep tt | ",
		"grep \"tty\" | salut || salut"};

	cr_redirect_stdout();
	for (int i = 0; i < 2; i++) {
		inst[i] = malloc(sizeof(instruction_t));
		inst[i]->full_instruction =
		my_strcpy(inst[i]->full_instruction, str[i]);
		inst[i]->valid = true;
		cr_assert_eq(get_pipe_number(inst[i]), 0);
	}
}

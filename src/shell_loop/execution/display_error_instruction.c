/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Display the right error message if the instruction is not valid
*/

#include <stdlib.h>
#include <stdio.h>
#include "instruction.h"

static void display_error_invalid_pipe(void)
{
	puts("Invalid null command.");
}

static void display_error_invalid_redirect(void)
{
	puts("Missing name for redirect.");
}

static void display_error_ambiguous_redirect(void)
{
	puts("Ambiguous output redriect.");
	puts("Ambiguous input redriect.");
}

void display_error_instruction(instruction_t *instruction)
{
	if (instruction->valid == false && instruction->pipe == NULL) {
		display_error_invalid_pipe();
		return;
	}
	for (int i = 0; instruction->pipe[i]; i++) {
		if (instruction->pipe[i]->error == INVALID_PIPE)
			display_error_invalid_pipe();
		if (instruction->pipe[i]->error == INVALID_REDIRECT_NAME)
			display_error_invalid_redirect();
		if (instruction->pipe[i]->error == AMBIGUOUS_REDIRECT)
			display_error_ambiguous_redirect();
	}
}

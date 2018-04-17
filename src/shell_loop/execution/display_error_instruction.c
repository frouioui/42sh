/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Display the right error message if the instruction is not valid
*/

#include <stdlib.h>
#include "instruction.h"
#include "mylib.h"

static void display_error_invalid_pipe(void)
{
	my_putstr("Invalid null command.\n");
}

static void display_error_invalid_redirect(void)
{
	my_putstr("Missing name for redirect.\n");
}

static void display_error_ambiguous_redirect(void)
{
	my_putstr("Ambiguous output redriect.\n");
	my_putstr("Ambiguous input redriect.\n");
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

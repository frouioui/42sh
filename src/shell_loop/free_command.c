/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Free the whole command_line struct and its sub structs / arrays.
*/

#include <stdlib.h>
#include "instruction.h"
#include "execution.h"

static void free_pipe(pipe_t *pipe)
{
	free(pipe->full_instruction);
	if (pipe->path_exec != NULL)
		free(pipe->path_exec);
	free_array_string(pipe->args);
}

static void free_instruction(instruction_t *instruction)
{
	free(instruction->full_instruction);
	for (unsigned int i = 0; i < instruction->number_of_pipe; i++) {
		free_pipe(instruction->pipe[i]);
		free(instruction->pipe[i]);
	}
	free(instruction->pipe);
}

void free_command(command_line_t *command)
{
	for (unsigned int i = 0; i < command->number_instruction; i++) {
		free_instruction(command->instruction[i]);
		free(command->instruction[i]);
	}
	free(command->full_command);
	free(command->instruction);
	free(command);
}

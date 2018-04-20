/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Main file of the "execution" functions
*/

#include "shell.h"
#include "instruction.h"
#include "execution.h"

static bool is_instruction_valid(instruction_t *instruction)
{
	if (instruction->valid == false)
		return (false);
	for (int i = 0; instruction->pipe[i]; i++) {
		if (instruction->pipe[i]->valid == false)
			return (false);
	}
	return (true);
}

static void execute_instruction(shell_t *shell, command_line_t *command,
	instruction_t **instruction, unsigned int nb)
{
	if (is_instruction_valid(command->instruction[nb]) &&
	command->instruction[nb]->number_of_pipe > 1) {
		multiple_execution(shell, command->instruction[nb]);
	} else if (is_instruction_valid(command->instruction[nb])) {
		simple_execution(shell, command->instruction[nb]);
	} else {
		shell->code = 1;
		display_error_instruction(command->instruction[nb]);
	}
	command->instruction[nb]->last_code = shell->code;
}

unsigned int execute_command(shell_t *shell, command_line_t *command)
{
	for (unsigned int nb = 0; command->instruction[nb] &&
	shell->state == OK; nb++) {
		if (is_condition_valid(command->instruction, nb)) {
			execute_instruction(shell, command,
			command->instruction, nb);
		}
	}
	return (shell->code);
}

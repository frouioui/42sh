/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** File of the main parsing function
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"

instruction_t *new_instruction(char *str)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (instruction == NULL)
		return (NULL);
	instruction->full_instruction = malloc(sizeof(char) *
		(strlen(str) + 1));
	if (instruction->full_instruction == NULL)
		return (NULL);
	instruction->valid = true;
	instruction->condition = NO;
	instruction->last_code = 0;
	return (instruction);
}

static unsigned int get_instruction(command_line_t *command, char *input)
{
	unsigned int j = 0;
	unsigned int i = 0;

	while (input[i] && j < command->number_instruction) {
		command->instruction[j] = new_instruction(input);
		if (!command->instruction[j])
			return (FAILURE);
		for (int a = 0; input[i] &&
		INSTRUCTION_SEPARATOR_ALL(input, i) == 0; a++) {
			command->instruction[j]->full_instruction[a]
			= input[i++];
			command->instruction[j]->full_instruction[a + 1] = 0;
		}
		fix_extra_spaces(command->instruction[j]->full_instruction);
		get_condition(command->instruction[j], input + i);
		for (i; input[i] && (INSTRUCTION_SEPARATOR_ONE(input, i)
			|| input[i] == ' '); i++);
		j++;
	}
	return (SUCCESS);
}

command_line_t *get_command_line(bool bonus, char *user_input, char **env,
	char **local)
{
	command_line_t *command = malloc(sizeof(command_line_t));
	unsigned int err = 0;

	if (command == NULL || !(command->full_command = strdup(user_input)))
		return (NULL);
	command->valid = true;
	command->number_instruction = get_number_instruction(user_input);
	command->instruction = malloc(sizeof(instruction_t *) *
		(command->number_instruction + 1));
	if (command->instruction == NULL)
		return (NULL);
	command->instruction[command->number_instruction] = NULL;
	if (get_instruction(command, user_input) == FAILURE)
		return (NULL);
	err = fill_up_instruction(bonus, command->instruction, env, local);
	if (err == FAILURE)
		return (NULL);
	else if (err == SKIP)
		command->valid = false;
	return (command);
}

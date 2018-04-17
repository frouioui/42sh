/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Fill the whole instruction structure after the expression was given
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"
#include "instruction.h"

unsigned int fill_up_instruction(bool bonus, instruction_t **instruction,
	char **env)
{
	for (unsigned int i = 0; instruction[i]; i++) {
		get_pipe_number(instruction[i]);
		if (instruction[i]->valid == false)
			return (SKIP);
		instruction[i]->actual_pipe = instruction[i]->number_of_pipe
		- 1;
		if (instruction[i]->valid == true)
			instruction[i]->pipe = get_pipe(bonus,
				instruction[i], env);
		if (instruction[i]->valid && instruction[i]->pipe == NULL)
			return (FAILURE);
		if (instruction[i]->valid == false)
			return (SKIP);
	}
	return (SUCCESS);
}

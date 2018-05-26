/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Fill the whole instruction structure after the expression was given
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"
#include "instruction.h"

unsigned int fill_up_instruction(bool bonus, instruction_t **instruction,
	char **env, char **local)
{
	for (unsigned int i = 0; instruction[i]; i++) {
		get_pipe_number(instruction[i]);
		if (instruction[i]->valid == false)
			return (SKIP);
		instruction[i]->actual_pipe = 0;
		if (instruction[i]->valid == true)
			instruction[i]->pipe = get_pipe(bonus,
				instruction[i], env, local);
		if (instruction[i]->valid && instruction[i]->pipe == NULL)
			return (FAILURE);
		if (instruction[i]->valid == false)
			return (SKIP);
	}
	return (SUCCESS);
}

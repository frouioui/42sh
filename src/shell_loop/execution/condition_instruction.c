/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check the condition of execution for the current instruction
*/

#include <stdbool.h>
#include "instruction.h"

void condition_not_valid(instruction_t **instruction, unsigned int nb)
{
	instruction[nb]->last_code = instruction[nb - 1]->last_code;
}

bool is_condition_valid(instruction_t **instruction, unsigned int nb)
{
	if (nb == 0)
		return (true);
	if (instruction[nb - 1]->condition == NO)
		return (true);
	if (instruction[nb - 1]->condition == AND &&
	instruction[nb - 1]->last_code == 0)
		return (true);
	if (instruction[nb - 1]->condition == OR &&
	instruction[nb - 1]->last_code != 0)
		return (true);
	return (false);
}

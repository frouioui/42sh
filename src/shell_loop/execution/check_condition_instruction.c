/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check the condition of execution for the current instruction
*/

#include "instruction.h"

unsigned int is_condition_valid(instruction_t **instruction, unsigned int act)
{
	if (act == 0)
		return (1);
	if (instruction[act - 1]->condition == NO)
		return (1);
	if (instruction[act - 1]->condition == AND &&
	instruction[act - 1]->last_code == 0)
		return (1);
	if (instruction[act - 1]->condition == OR &&
	instruction[act - 1]->last_code == 1)
		return (1);
	return (0);
}

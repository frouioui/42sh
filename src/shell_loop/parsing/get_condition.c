/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the condition of the given instruction
*/

#include <stdlib.h>
#include "instruction.h"

void get_condition(instruction_t *instruction, char *input)
{
	unsigned int i = 0;

	while (input[i] && SPACE_TAB(input[i]))
		i++;
	if (IS_AND_CONDITION(input, i) == 1)
		instruction->condition = AND;
	if (IS_OR_CONDITION(input, i) == 1)
		instruction->condition = OR;
	if (IS_NO_CONDITION(input, i) == 1)
		instruction->condition = NO;
}

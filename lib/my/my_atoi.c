/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Get an int out of a string.
*/

#include "instruction.h"

int my_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i]) {
		if (DIGIT(str[i]) == 0)
			return (0);
		result = result * 10;
		result += str[i] - 48;
		i = i + 1;
	}
	return (result);
}

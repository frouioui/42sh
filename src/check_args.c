/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Check if the given args are equal to 1
*/

#include <stdio.h>
#include "shell.h"

int check_args(int argc)
{
	if (argc != 1 && argc != 2) {
		puts("You must give 0 arguments to the program.");
		return (FAILURE);
	}
	return (SUCCESS);
}

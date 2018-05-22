/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check if the given args are equal to 1
*/

#include "shell.h"
#include "mylib.h"

int check_args(int argc)
{
	if (argc != 1 && argc != 2) {
		my_putstr("You must give 0 arguments to the program.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

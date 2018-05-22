/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Check if the given args are equal to 1
*/

#include "shell.h"
#include "mylib.h"
#include "script.h"

int check_args(int argc, char **argv)
{
	if (argc != 1 && argc != 2) {
		my_putstr("You must give 0 arguments to the program.\n");
		return (FAILURE);
	}
	if (argc == 2 && argv[1] && !check_script(argv[1])) {
		my_putstr("The given argument must be a valid script\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

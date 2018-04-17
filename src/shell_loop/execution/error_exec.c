/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Display the error command not find.
*/

#include "mylib.h"

void display_error_execution(char *filename)
{
	my_putstr(filename);
	my_putstr(": Command not found.\n");
}

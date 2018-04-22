/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Function my_putstr, calling my_putchar. Display : (char *str).
*/

#include "mylib.h"

void my_putstr(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}

/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Fix all the extra space at the begining and the end of string
*/

#include <string.h>

void fix_extra_spaces(char *str)
{
	int size = strlen(str) - 1;
	int i;
	int a;

	for (i = 0; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
	for (a = 0; str[a + i]; a++)
		str[a] = str[a + i];
	str[a] = '\0';
	while ((str[size] == ' ' || str[size] == '\t') && size > 0) {
		str[size] = '\0';
		size--;
	}
}

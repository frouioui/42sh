/*
** EPITECH PROJECT, 2017
** count_words.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

int count_words(char *str)
{
	int i;
	int words = 0;

	if (str == NULL)
		return (0);
	if (strlen(str) == 0)
		return (0);
	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] == ' ' || str[i] == '\t') &&
		is_printable(str[i+1])) {
			words += 1;
		}
	}
	return (++words);
}

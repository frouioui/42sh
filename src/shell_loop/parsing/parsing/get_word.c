/*
** EPITECH PROJECT, 2017
** get_word.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

static void check_reset(int *i, int *j, int reset)
{
	if (reset == 0) {
		*i = 0;
		*j = 0;
	}
}

static void check_inib(char *str, int *i, char *c)
{
	if (str[*i] == '\'' || str[*i] == '"') {
		*c = str[*i];
		*i = *i + 1;
	}
}

char *get_word(char *str, int reset)
{
	static int i = 0;
	static int j = 0;
	char c = ' ';

	check_reset(&i, &j, reset);
	while ((str[i] != '"' || str[i] != '\'') && str[i] != '\0'
	&& isspace(str[i]))
		i++;
	check_inib(str, &i, &c);
	j = i;
	while (str[i] != '\0') {
		if ((c == str[i]) || (c == ' ' && isspace(str[i])))
			break;
		i++;
	}
	return (my_strcpy_words_parse(str, j, i++));
}

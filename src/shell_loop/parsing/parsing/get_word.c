/*
** EPITECH PROJECT, 2017
** get_word.c
** File description:
** florian.davasse@epitech.eu
*/

#include "minishell.h"

/*int check_inib(char *str, int j)
{
	for (int i = j; str[i] )
}*/

char *get_word(char *str, int reset)
{
	static int i = 0;
	static int j = 0;

	if (reset == 1) {
		i = 0;
		j = 0;
	}
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i++;
	j = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	check_inib(str, j);
	return (my_strcpy_words_parse(str, j, i));
}

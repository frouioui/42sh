/*
** EPITECH PROJECT, 2017
** my_strcpy_words.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

char *my_strcpy_words_parse(char *str, int start, int end)
{
	int i = start;
	int j = 0;
	char *new_str = malloc(sizeof(char) * ((end - start) + 2));

	while (i < end && str[i] != '\0') {
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

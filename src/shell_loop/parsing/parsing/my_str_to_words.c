/*
** EPITECH PROJECT, 2017
** my_str_to_words.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

char **my_str_to_words(char *str)
{
	char **words = malloc(sizeof(char *) * 1);
	char *temp = NULL;

	words[0] = NULL;
	for (int i = 0; (temp = get_word(str, i)) != NULL; i++) {
		words = realloc(words, sizeof(char *) * (i + 2));
		words[i] = temp;
		words[i + 1] = NULL;
	}
	if (words[0] == NULL)
		words = NULL;
	return (words);
}

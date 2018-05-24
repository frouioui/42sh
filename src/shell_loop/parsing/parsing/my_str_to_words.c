/*
** EPITECH PROJECT, 2017
** my_str_to_words.c
** File description:
** florian.davasse@epitech.eu
*/

#include "minishell.h"

char **my_str_to_words(char *str)
{
	int words = count_words(str);
	char **word = malloc(sizeof(char *) * (words + 1));

	if (words == 0)
		return (NULL);
	for (int i = 0; i < words; i++) {
		if (i == 0)
			word[i] = get_word(str, 1);
		else
			word[i] = get_word(str, 0);
	}
	word[words] = NULL;
	return (word);
}

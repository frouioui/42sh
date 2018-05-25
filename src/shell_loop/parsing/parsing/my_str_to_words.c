/*
** EPITECH PROJECT, 2017
** my_str_to_words.c
** File description:
** florian.davasse@epitech.eu
*/

#include "shell.h"

char **my_str_to_words(char *str)
{
	//gcc get_word.c my_strcpy_words.c -I../../../../include -g3 && ./a.out
	//char *str = "\"lol c un test \"mdr 'xd sa march lol'     ptdr";
	char **words = malloc(sizeof(char*) * 1);
	char *temp = NULL;

	words[0] = NULL;
	for (int i = 0; (temp = get_word(str, i)) != NULL; i++) {
		words = realloc(words, sizeof(char*) * (i+2));
		words[i] = temp;
		//printf("LE MOT : '%s'\n", words[i]);
		words[i+1] = NULL;
	}
	if (words[0] == NULL)
		words = NULL;
	return (words);
}

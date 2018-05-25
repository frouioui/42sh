/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Search key words in script file
*/

#include "script.h"
#include <string.h>

static void search_elsif(cond_t *cond, char **words_array)
{
	if (!words_array[0] || !words_array[1])
		return;
	if (!strcmp(words_array[0], "else") && !strcmp(words_array[1], "if"))
		cond->key = ELSIF;
}

static bool keyword_exist(cond_t *cond, char **words_array)
{
	cond_t cond_array[NB_COND] = {{IF, "if", NULL, false},
		{ELSE, "else", NULL, false}, {WHILE, "while", NULL, false},
		{FOREACH, "foreach", NULL, false},
		{WHICH, "which", NULL, false}, {WHERE, "where", NULL, false}};

	for (int i = 0; i < NB_COND; i += 1)
		if (!strcmp(cond_array[i].condition, words_array[0]))
			cond->key = cond_array[i].key;
	if (cond->key == ELSE)
		search_elsif(cond, words_array);
	if (cond->key == EMPTY)
		return (false);
	return (true);
}

int search_keyword(cond_t *cond_line, char *line)
{
	char **words_array = cut_line(line);

	if (!words_array)
		return (FAILURE);
	if (keyword_exist(cond_line, words_array) == false) {
		free_array_string(words_array);
		return (SKIP);
	}
	if (fill_cond(cond_line, line, words_array) != true) {
		free_array_string(words_array);
		return (FAILURE);
	}
	free_array_string(words_array);
	return (SUCCESS);
}

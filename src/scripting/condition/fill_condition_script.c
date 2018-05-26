/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Conditional structure initialization
*/

#include "script.h"

static bool copy_command(cond_t *cond, char *line)
{
	int start = 0;

	for (int i = 0; line[i] != '\0'; i += 1)
		if (line[i] == ')')
			start = i;
	if (line[start + 1] == '\0') {
		if (cond->key == IF || cond->key == ELSIF) {
			puts("if: Empty if.");
			return (false);
		}
		else if (cond->key == ELSE)
			return (true);
	}
	cond->command = malloc(sizeof(char) * (strlen(line) - start));
	if (!cond->command)
		return (false);
	for (int i = start + 1, j = 0; line[i] != '\0'; i += 1, j += 1)
		cond->command[j] = line[i];
	cond->command[strlen(line) - start - 1] = '\0';
	return (true);
}

static bool search_then(cond_t *cond, char *line, char **words_array)
{
	bool then_exist = false;

	for (int i = 0; words_array[i]; i += 1)
		if (!strcmp(words_array[i], "then"))
			then_exist = true;
	if (!then_exist && cond->key != ELSE)
		cond->end = true;
	if (!then_exist || cond->key == ELSE)
		if (copy_command(cond, line) != true)
			return (false);
	return (true);
}

static bool copy_condition(cond_t *cond, char *line, int start, int end)
{
	char **words_array = cut_line(line);

	cond->condition = malloc(sizeof(char) * (end - start));
	if (!cond->condition || !words_array)
		return (false);
	for (int i = start + 1, j = 0;i < end; i += 1, j += 1)
		cond->condition[j] = line[i];
	cond->condition[end - start - 1] = '\0';
	if (cond->key != IF && cond->key != ELSIF && cond->key != ELSE)
		if (line[end + 1] != '\0') {
			my_putstr(words_array[0]);
			puts(": Expression Syntax.");
			free_array_string(words_array);
			return (false);
		}
	free_array_string(words_array);
	return (true);
}

static bool check_condition(cond_t *cond, char *line)
{
	int open_bracket = 0;
	int close_bracket = 0;

	for (int i = 0; line[i] != '\0'; i += 1) {
		if (line[i] == '(')
			open_bracket = i;
		else if (line[i] == ')')
			close_bracket = i;
	}
	if (!open_bracket || !close_bracket)
		return (false);
	if (copy_condition(cond, line, open_bracket, close_bracket) != true)
		return (false);
	return (true);
}

bool fill_cond(cond_t *cond, char *line, char **words_array)
{
	if (check_condition(cond, line) != true)
		return (false);
	if (cond->key == IF || cond->key == ELSIF || cond->key == ELSE)
		if (search_then(cond, line, words_array) != true)
			return (false);
	return (true);
}

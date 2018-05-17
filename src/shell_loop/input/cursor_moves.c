/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Move cursor functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "input.h"
#include "mylib.h"

static int simple_move(char *input, int *i, int c, binding_t *binding)
{
	if (c == binding->left) {
		if (*i == 0)
			return (*i);
		my_putstr("\033[1D");
		(*i)--;
	} else if (c == binding->right) {
		if (*i >= (int)strlen(input))
			return (*i);
		my_putstr("\033[1C");
		(*i)++;
	}
	return (*i);
}

static int longer_move(char *input, int *i, int c, binding_t *binding)
{
	int ratio = 0;

	if (c == binding->end) {
		ratio = strlen(input) - *i;
		*i = strlen(input);
		for (int a = 0; a < ratio; a++)
			my_putstr("\033[1C");
	} else if (c == binding->begin) {
		ratio = 0 + *i;
		(*i) = 0;
		for (int a = 0; a < ratio; a++)
			my_putstr("\033[1D");
	}
	return (*i);
}

static int add_in_cursor(char *input, int *i, int c, binding_t *binding)
{
	int ratio = 0;

	if (c == binding->suppr) {
		if (strlen(input) == 0 || (*i) == (int)strlen(input))
			return (*i);
		for (int a = (*i); input[a + 1]; a++, ratio++) {
			input[a] = input[a + 1];
		}
		input[*i + ratio] = '\0';
		ratio = 0;
		my_putstr(CLEAR_END_LINE);
		write(0, input + *i, strlen(input + *i));
		for (int a = 0; a != (int)strlen(input) - *i; a++)
			my_putstr("\033[1D");
	}
	return (*i);
}

int cursor_moves(char *input, int c, int *i, binding_t *binding)
{
	if (c != binding->right && c != binding->left && c != binding->end &&
	c != binding->begin && c != binding->suppr)
		return (*i);
	if (c == binding->right || c == binding->left) {
		return (simple_move(input, i, c, binding));
	} else if (c == binding->end || c == binding->begin) {
		return (longer_move(input, i, c, binding));
	} else {
		return (add_in_cursor(input, i, c, binding));
	}
	return (*i);
}

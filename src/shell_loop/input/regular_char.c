/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Write and fill the input with the regular char
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "input.h"

static char *realloc_input(char *old_input, int index, int to_add)
{
	char *new = malloc(sizeof(char) * (strlen(old_input) + 2));
	int i = 0;

	if (new == NULL)
		return (NULL);
	new[strlen(old_input)] = '\0';
	new[strlen(old_input) + 1] = '\0';
	for (i = 0; old_input[i] && i < index; i++)
		new[i] = old_input[i];
	new[i++] = to_add;
	for (i = i; old_input[i - 1]; i++)
		new[i] = old_input[i - 1];
	new[i] = '\0';
	free(old_input);
	return (new);
}

static char *backspace_input(char *input, int *c, int *i, int fd)
{
	int a = 0;

	if (*i > 0) {
		for (a = (*i) - 1; input[a]; a++)
			input[a] = input[a + 1];
		input[a] = '\0';
		*c = BACKSPACE;
		(*i)--;
		write(fd, c, 1);
		write(fd, CLEAR_END_LINE, 3);
		write(fd, input + *i, strlen(input + *i));
		for (int a = 0; a < (int)strlen(input + *i); a++)
			my_putstr("\033[1D");
	}
	return (input);
}

static char *add_char_input(char *input, int c, int *i)
{
	input = realloc_input(input, *i, c);
	(*i)++;
	return (input);
}

static void print_input(char *input, int c, int *i, int fd)
{
	int ratio = 0;

	if (input[*i] == '\0') {
		write(fd, &c, 1);
	} else {
		write(fd, CLEAR_END_LINE, 3);
		for (int a = *i - 1; input[a]; a++, ratio++)
			write(fd, &input[a], 1);
		for (int a = 0; a < ratio - 1; a++)
			my_putstr("\033[1D");
	}
}

char *regular_char(char *input, int c, int *i, int fd)
{
	if (c < 32 || c > 127)
		return (input);
	if (c == DEL) {
		input = backspace_input(input, &c, i, fd);
		return (input);
	} else {
		input = add_char_input(input, c, i);
	}
	print_input(input, c, i, fd);
	return (input);
}

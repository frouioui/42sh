/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the input from the terminal and returns it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

static char *realloc_input(char *old_input, int index, int to_add)
{
	char *new = malloc(sizeof(char) * (strlen(old_input) + 2));

	if (new == NULL)
		return (NULL);
	if (to_add != BACKSPACE || strlen(old_input) != 0 || (to_add >= 32
		&& to_add <= 126))
		write(1, &to_add, 1);
	new[strlen(old_input)] = '\0';
	new[strlen(old_input) + 1] = '\0';
	for (int i = 0; old_input[i]; i++)
		new[i] = old_input[i];
	if (to_add == BACKSPACE)
		strlen(old_input) > 0 ? new[strlen(old_input) - 1] = '\0' : 0;
	else
		new[strlen(old_input)] = to_add;
	free(old_input);
	return (new);
}

// Write a new line only when needed.
static bool special_input(shell_t *shell, int c)
{
	if (c == shell->binding->clear || c == shell->binding->exit)
		return (true);
	if (c == EOT || c == '\n') {
		write(1, "\n", 1);
		return (true);
	} else if ((c < 32 || c > 126) && c != DEL) {
		return (true);
	}
	return (false);
}

static bool end_loop(shell_t *shell, int c)
{
	if (c == shell->binding->clear || c == shell->binding->exit
		|| c == EOT || c == '\n')
		return (false);
	return (true);
}

/*
** Main loop of the input handling, get all the char and fills the input ptr.
** The loop will stop whenever the input char is a special char (key binding).
*/
static char *get_chars_from_term(shell_t *shell, int fd)
{
	int c = 1;
	char *input = malloc(sizeof(char) * 1);
	unsigned int index = 0;
	int res = 1;

	if (input == NULL)
		return (NULL);
	input[0] = '\0';
	while (input && res > 0 && end_loop(shell, c) == true ) {
		c = 1;
		res = read(fd, &c, sizeof(int));
		shell->binding->code = c;
		if (special_input(shell, c) == false) {
			c == DEL ? c = BACKSPACE : 0;
			input = realloc_input(input, index, c);
		}
	}
	return (c == EOT ? NULL : input);
}

char *get_input(shell_t *shell, int fd)
{
	char *input = NULL;

	if (shell->term == false) {
		return (get_next_line(fd));
	} else {
		input = get_chars_from_term(shell, fd);
	}
	return (input);
}

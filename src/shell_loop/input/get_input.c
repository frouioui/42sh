/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the input from the terminal and returns it.
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"
#include "input.h"

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

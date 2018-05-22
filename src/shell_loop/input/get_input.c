/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the input from the terminal and returns it.
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "mylib.h"
#include "input.h"

// Main input management function
char *get_input(shell_t *shell, int fd_term, int fd_gnl)
{
	char *input = NULL;

	if (shell->term == false) {
		input = get_next_line(fd_gnl);
	} else {
		input = get_chars_from_term(shell, fd_term);
	}
	if (input != NULL)
		write(fd_term, "\n", 1);
	return (input);
}

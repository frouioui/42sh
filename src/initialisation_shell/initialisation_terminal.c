/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Set the terminal to the right term caps mode
*/

#include <string.h>
#include <stdio.h>
#include <term.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int get_term_caps(struct termios *new, char **env)
{
	char *term = my_get_env(env, "TERM");

	if (term == NULL)
		return (1);
	if (tgetent(NULL, term) < 0 || tcgetattr(0, new) < 0)
		return (1);
	free(term);
	return (0);
}

bool init_terminal(shell_t *shell)
{
	struct termios new;

	if (!isatty(0))
		return (false);
	tcgetattr(0, &shell->terminal.old);
	if (get_term_caps(&new, shell->env) == 1)
		return (false);
	new.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &(new)) == 1)
		return (false);
	return (true);
}

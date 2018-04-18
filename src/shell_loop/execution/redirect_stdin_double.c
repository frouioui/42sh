/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Functions for the redirection of the stdin (double).
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "execution.h"
#include "instruction.h"
#include "mylib.h"

static void get_user_stdin_input(pipe_t *pipe, char *arg)
{
	char *input = NULL;

	while ((input = get_next_line(0)) != NULL && strcmp(input, arg) != 0) {
		if (write(pipe->pipe[1], input, strlen(input)) == -1)
			perror("write");
		write(pipe->pipe[1], "\n", 1);
		free(input);
	}
}

void redirect_stdin_double(pipe_t *pipe_act)
{
	if (pipe(pipe_act->pipe) == -1)
		perror("pipe");
	get_user_stdin_input(pipe_act, pipe_act->file_redirect);
	close(pipe_act->pipe[1]);
	dup2(pipe_act->pipe[0], 0);
}

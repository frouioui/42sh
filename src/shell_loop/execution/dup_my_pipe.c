/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Dup the pipe's file descriptor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "execution.h"
#include "instruction.h"

static void dup_first(shell_t *shell, pipe_t *pipe, int **fd,
	unsigned int actual)
{
	int *fd1 = fd[actual];

	for (int i = 0; fd[i]; i++)
		if (fd[i] != fd1) {
			close(fd[i][1]);
			close(fd[i][0]);
		}
	if (dup2(fd1[1], 1) == -1)
		perror("dup");
	if (pipe->redirect == true)
		redirect_pipe(shell->bonus, pipe);
	close(fd1[0]);
}

static void dup_last(shell_t *shell, pipe_t *pipe, int **fd,
	unsigned int actual)
{
	int *fd1 = fd[actual - 1];

	for (int i = 0; fd[i]; i++)
		if (fd[i] != fd1) {
			close(fd[i][1]);
			close(fd[i][0]);
		}
	if (dup2(fd1[0], 0) == -1)
		perror("dup");
	if (pipe->redirect == true)
		redirect_pipe(shell->bonus, pipe);
	close(fd1[1]);
}

static void dup_between(shell_t *shell, pipe_t *pipe, int **fd,
	unsigned int actual)
{
	int *fd1 = fd[actual];
	int *fd2 = fd[actual - 1];

	for (int i = 0; fd[i]; i++)
		if (fd[i] != fd1 && fd[i] != fd2) {
			close(fd[i][1]);
			close(fd[i][0]);
		}
	if (pipe->redirect == true)
		redirect_pipe(shell->bonus, pipe);
	if (pipe->type_redirect != STDOUT_SIMPLE &&
	pipe->type_redirect != STDOUT_DOUBLE)
		if (dup2(fd1[1], 1) == -1)
			perror("dup");
	if (pipe->type_redirect != STDIN_SIMPLE &&
	pipe->type_redirect != STDIN_DOUBLE)
		if (dup2(fd2[0], 0) == -1)
			perror("dup");
	close(fd1[0]);
	close(fd2[1]);
}

int dup_my_pipe(shell_t *shell, instruction_t *instruction,
	unsigned int actual, int **fd)
{
	if (actual == 0) {
		dup_first(shell, instruction->pipe[actual], fd, actual);
	} else if (actual == instruction->number_of_pipe - 1) {
		dup_last(shell, instruction->pipe[actual], fd, actual);
	} else {
		dup_between(shell, instruction->pipe[actual], fd,
			actual);
	}
	return (0);
}

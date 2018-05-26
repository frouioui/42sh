/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Main file for all the "multiple execution" command (pipes)
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdio.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static void wait_all(int *stat, shell_t *shell, instruction_t *inst, int **fd)
{
	unsigned int i = 0;
	unsigned int nb_pipe;

	if (stat == NULL)
		exit(84);
	while (i < inst->number_of_pipe - 1) {
		(fd[i][0] != -1) ? close(fd[i][0]) : 0;
		(fd[i][1] != -1) ? close(fd[i][1]) : 0;
		i++;
	}
	for (i = 0; i < inst->number_of_pipe - 1; i++) {
		wait(&(stat[i]));
		if (stat[i] == 250)
			exit(shell->code);
		stat[i] == 0 && shell->code != 0 ? 0 :
		(shell->code = stat[i] / 256);
		check_sig(shell, stat[i], inst->pipe[i]->ampersand);
	}
}

static void free_pipes(int **fd)
{
	for (int i = 0; fd[i]; i++) {
		(fd[i][0] != -1) ? close(fd[i][0]) : 0;
		(fd[i][1] != -1) ? close(fd[i][1]) : 0;
	}
	for (int i = 0; fd[i]; i++)
		free(fd[i]);
	free(fd);
}

static int init_stat(int *stat, instruction_t *instruction)
{
	if (stat == NULL)
		return (0);
	for (unsigned int i = 0; i < instruction->number_of_pipe + 1; i++) {
		stat[i] = 0;
	}
	return (1);
}

void multiple_execution(shell_t *shell, instruction_t *instruction)
{
	pid_t pid = 0;
	int **fd = NULL;
	int *stat = malloc(sizeof(int) * (instruction->number_of_pipe + 2));
	int actual = instruction->actual_pipe;

	fd = create_pipe(instruction->number_of_pipe);
	if (fd == NULL)
		return;
	if (!init_stat(stat, instruction) || !fd)
		exit(84);
	if ((pid = fork()) == -1)
		exit(84);
	if (pid == 0)
		exec_pipe(shell, instruction, fd, pid);
	else {
		wait_all(stat, shell, instruction, fd);
		free_pipes(fd);
	}
	free(stat);
}

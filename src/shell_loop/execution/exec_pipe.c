/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Recursive function for the execution of the pipes
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

void bad_archi(shell_t *shell, char *arg)
{
	printf("%s: Exec format error. Wrong Architecture.\n", arg);
	shell->code = 1;
}

static int exec_parent(shell_t *shell, instruction_t *inst, int **fd)
{
	unsigned int actual = inst->actual_pipe;

	if (is_builtins(inst->pipe[actual]->args[0]) == true) {
		dup_my_pipe(shell, inst, actual, fd) == -1 ? exit(84) : 0;
		exec_builtins(shell, inst->pipe[actual]) == -1 ? exit(84) : 0;
		exit(-6);
	} else {
		inst->pipe[actual]->path_exec =
		get_path_exec(inst->pipe[actual], shell);
		inst->pipe[actual]->path_exec == NULL ? shell->code = 1 : 0;
		shell->code == 1 ? exit(shell->code) : 0;
		dup_my_pipe(shell, inst, actual, fd) == -1 ? exit(1) : 0;
		if (execve(inst->pipe[actual]->path_exec,
		inst->pipe[actual]->args, shell->env) == -1)
			errno == 8 ? bad_archi(shell, inst->pipe[actual]->
			args[0]) : folder_error(shell,
				errno, inst->pipe[actual]-> args[0], 1);
		exit(1);
	}
	return (shell->state);
}

void exec_pipe(shell_t *shell, instruction_t *instruction, int **fd, pid_t pid)
{
	pid_t pid2 = 0;
	int stat = 0;

	if (UNSET_PIPE)
		 if (pipe(fd[instruction->actual_pipe]) == SYS_CALL_ERR)
		 	exit(84);
	if ((pid2 = fork()) == -1)
		exit(84);
	if (pid2 != 0) {
		instruction->actual_pipe++;
		if (instruction->actual_pipe != NB_PIPE)
			exec_pipe(shell, instruction, fd, pid2);
		else if (instruction->actual_pipe == NB_PIPE)
			shell->state = exec_parent(shell, instruction, fd);
	} else {
		shell->state = exec_parent(shell, instruction, fd);
	}
}

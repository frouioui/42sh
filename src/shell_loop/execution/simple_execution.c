/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Simple execution functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

static void execute_child(shell_t *shell, pipe_t *pipe)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1) {
		exit(84);
	} else if (pid == 0) {
		redirect_pipe(shell->bonus, pipe);
		if (execve(pipe->path_exec, pipe->args, shell->env) == -1)
			errno == 8 ? bad_archi(shell, pipe->args[0])
			: folder_error(shell, errno, pipe->args[0], 1);
		exit(shell->code);
	} else {
		!wait(&status) ? perror(pipe->args[0]) : 0;
		shell->code = status >= 256 ? status / 256 : status;
		check_sig(shell, status);
	}
}

void simple_execution(shell_t *shell, instruction_t *instruction)
{
	if (is_builtins(instruction->pipe[0]->args[0]) == true) {
		if (exec_builtins(shell, instruction->pipe[0]) == -1)
			shell->code = 1;
		else
			shell->code = 0;
	} else if ((instruction->pipe[0]->path_exec =
		get_path_exec(instruction->pipe[0], shell)) != NULL) {
		execute_child(shell, instruction->pipe[0]);
	} else {
		shell->code = 1;
	}
}

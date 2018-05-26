/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Simple execution functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "process_gestion.h"
#include "shell.h"
#include "instruction.h"
#include "execution.h"

static bool wait_correctly(shell_t *shell, pipe_t pipe, int *status, pid_t pid)
{
	if (!shell)
		return true;
	if (!pipe.ampersand) {
		!waitpid(pid, status, WUNTRACED) ? perror(pipe.args[0]) : 0;
		return false;
	}
	waitpid(pid, status, WNOHANG);
	return false;
}

static void execute_child(shell_t *shell, pipe_t *pipe)
{
	int status = 0;
	struct sigaction saves[2];
	pid_t pid = fork();

	(pid == -1) ? exit(84) : get_or_set_pid(false, pid, true, false);
	if (pid == 0) {
		redirect_pipe(shell->bonus, pipe);
		if (execve(pipe->path_exec, pipe->args, shell->env) == -1)
			errno == 8 ? bad_archi(shell, pipe->args[0])
			: folder_error(shell, errno, pipe->args[0], 1);
		exit(shell->code);
	} else {
		get_process(SAVES, pid, shell, *pipe);
		wait_correctly(shell, *pipe, &status, pid);
		shell->code = status >= 256 ? status / 256 : status;
		finish_connection(&saves[0], &saves[1]);
		check_sig(shell, status, pipe->ampersand);
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

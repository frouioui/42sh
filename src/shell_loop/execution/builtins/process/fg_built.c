/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** forward --> builtin that put a process in first plan
*/

#include "shell.h"

static void update_process(shell_t *shell, int stat, pid_t pid)
{
	running_process_t *process = get_process_from_pid(shell->process, pid);

	if (!process)
		return;
	if (WIFSIGNALED(stat) || WIFEXITED(stat))
		process->state = DONE;
	if (get_or_set_pid(true, 0, false, false).stop)
		process->state = SUSPEND;
	if (process->state == DONT_SET)
		process->state = RUNNING;
}

static bool set_up_fg(pid_t pid_to_wait, struct sigaction *saves[2])
{
	if (!pid_to_wait) {
		fputs("No current jobs\n", stderr);
		return (true);
	}
	get_or_set_pid(false, pid_to_wait, true, false);
	printf("SIGCONT :%d\n", pid_to_wait);
	if (kill(pid_to_wait, SIGCONT) == SYS_CALL_ERR)
		return (true);
	if (init_connection(saves[0], saves[1], do_it_to_child)) {
		fputs("fg: can't init correctly\n", stderr);
		return (true);
	}
	return (false);
}

int fg_built(shell_t *shell, pipe_t *pipe)
{
	struct sigaction saves[2];
	int wstatus = 0;
	pid_t pid_to_wait = (shell->process) ? shell->process->pid_process : 0;

	if (set_up_fg(pid_to_wait, SAVES))
		return (0);
	shell->process->state = RUNNING;
	waitpid(pid_to_wait, &wstatus, WUNTRACED);
	printf("%d\n", WEXITSTATUS(wstatus));
	update_process(shell, wstatus, pid_to_wait);
	if (finish_connection(&saves[0], &saves[1])) {
		fputs("fg: can't finish correctly\n", stderr);
		return (0);
	}
	return (0);
}

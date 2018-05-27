/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Connection
*/

#include "shell.h"

void do_it_to_child(int signum, siginfo_t *info, void *env)
{
	pid_connection_t pid = get_or_set_pid(true, 0, true, false);

	if (!pid.usabel)
		return;
	if (kill(pid.pid, signum) == SYS_CALL_ERR)
		fputs("KILL can't kill child process\n", stderr);
	else if (signum == SIGTSTP)
		get_or_set_pid(false, pid.pid, true, true);
}

bool init_connection(struct sigaction *save_one, struct sigaction *save_two,
	void (*do_it_to_child)(int, siginfo_t *, void *))
{
	if (sigaction(SIGINT, NULL, save_one) == SYS_CALL_ERR)
		return true;
	if (sigaction(SIGTSTP, NULL, save_two) == SYS_CALL_ERR)
		return true;
	if (change_action_of_signal(SIGINT, do_it_to_child))
		return true;
	if (change_action_of_signal(SIGTSTP, do_it_to_child))
		return true;
	return false;
}

bool finish_connection(struct sigaction *save_one , struct sigaction *save_two)
{
	if (sigaction(SIGINT, save_one, NULL) == SYS_CALL_ERR)
		return true;
	if (sigaction(SIGTSTP, save_two, NULL) == SYS_CALL_ERR)
		return true;
	return false;
}

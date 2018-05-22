/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** change_action_of_signal.c
*/

#include "shell.h"

bool change_action_of_signal(int signum, void (*act)(int, siginfo_t *, void *))
{
	struct sigaction changed_signal;

	if (sigaction(signum, NULL, &changed_signal) == SYS_CALL_ERR)
		return true;
	changed_signal.sa_flags = SA_SIGINFO;
	changed_signal.sa_sigaction = act;
	if (sigaction(signum, &changed_signal, NULL) == SYS_CALL_ERR)
		return true;
	return false;
}

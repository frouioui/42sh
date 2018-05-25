/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** child_protection
*/

#include <stdlib.h>
#include "shell.h"

void new_exit(int signum, siginfo_t *info, void *env)
{
	exit(0);
}

bool init_child_connection(void)
{
	if (change_action_of_signal(SIGINT, new_exit))
		return true;
	return false;
}

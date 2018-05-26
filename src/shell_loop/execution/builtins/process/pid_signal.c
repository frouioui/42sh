/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Functions that make the transfer of data between signal and
** standart execution
*/

#include "process_gestion.h"

pid_connection_t get_or_set_pid(bool get, pid_t pid, bool usabel, bool stop)
{
	static pid_connection_t connection = {0, false, false};

	if (get)
		return connection;
	connection.stop = stop;
	if (usabel) {
		connection.pid = pid;
		connection.usabel = true;
	} else
		connection.usabel = false;
	return connection;
}

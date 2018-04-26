/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Write down the given command to the history file.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"

void write_command_history(command_line_t *cmd, char **paths)
{
	int fd = 0;

	fd = open(paths[1], O_WRONLY | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd != -1) {
		write(fd, cmd->full_command, strlen(cmd->full_command));
		write(fd, "\n", 1);
		close(fd);
	}
}

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

void write_command_history(bool bonus, command_line_t *cmd)
{
	int fd = 0;

	if (bonus == false)
		return;
	fd = open(PATH_HISTORY_FILE, O_WRONLY | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd != -1) {
		for (unsigned int i = 0; i < cmd->number_instruction; i++) {
			write(fd, cmd->instruction[i]->full_instruction,
			strlen(cmd->instruction[i]->full_instruction));
			write(fd, "\n", 1);
		}
		close(fd);
	}
}

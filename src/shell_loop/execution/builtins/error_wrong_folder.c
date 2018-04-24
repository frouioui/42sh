/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** display the error message when the given folder isn't correct
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

void display_folder_error(shell_t *shell, char *folder, char *str, int fd)
{
	write(fd, folder, strlen(folder));
	write(fd, ": ", 2);
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	shell->code = 1;
}

void folder_error(shell_t *shell, int err, char *folder, int fd)
{
	if (err == ENOTDIR)
		display_folder_error(shell, folder, "Not a directory.", fd);
	if (err == EACCES)
		display_folder_error(shell, folder, "Permission denied.", fd);
	if (err == EISDIR)
		display_folder_error(shell, folder, "Is a directory.", fd);
	if (err == ENOENT || err == 0)
		display_folder_error(shell,
			folder, "No such file or directory.", fd);
}

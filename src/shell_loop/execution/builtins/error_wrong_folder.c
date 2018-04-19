/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** display the error message when the given folder isn't correct
*/

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "shell.h"
#include "mylib.h"

void display_folder_error(shell_t *shell, char *folder, char *str)
{
	my_putstr(folder);
	my_putstr(": ");
	my_putstr(str);
	my_putchar('\n');
	shell->code = 1;
}

void folder_error(shell_t *shell, int err, char *folder)
{
	if (err == ENOTDIR)
		display_folder_error(shell, folder, "Not a directory.");
	if (err == EACCES)
		display_folder_error(shell, folder, "Permission denied.");
	if (err == EISDIR)
		display_folder_error(shell, folder, "Is a directory.");
	if (err == ENOENT || err == 0)
		display_folder_error(shell,
			folder, "No such file or directory.");
}

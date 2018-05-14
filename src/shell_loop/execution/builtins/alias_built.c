/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** File of the alias builtin.
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

/*
** Get the full alias (its key and its value) from the pipe's args.
** Exemple :
** "ll ls -l colors"
** Will become : [ll] [ls -l colors].
*/
char *get_full_alias(char **args)
{
	char *alias = NULL;
	int size = 0;

	for (int i = 1; args[i]; i++)
	size += strlen(args[i]) + 1;
	alias = malloc(sizeof(char) * (size * 2));
	if (alias == NULL)
		return (NULL);
	alias[0] = '\0';
	for (int i = 1; args[i]; i++) {
		alias = strcat(alias, args[i]);
		alias = strcat(alias, " \0");
	}
	return (alias);
}

/*
** Simply opens the file and returns its fd.
*/
static int open_alias(char *path)
{
	int fd = open(path, O_RDWR | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	return (fd);
}

/*
** Display all the alias until EOF.
*/
static void display_alias(shell_t *shell, pipe_t *pipe)
{
	int fd = open_alias(shell->paths[0]);
	char c = '\0';

	if (fd == -1)
		return;
	while (read(fd, &c, 1))
		write(pipe->fd, &c, 1);
	close(fd);
}

/*
** Create a simple alias at the end of the alias file.
*/
static void create_alias(shell_t *shell, pipe_t *pipe)
{
	char *full_alias = get_full_alias(pipe->args);
	int fd = open_alias(shell->paths[0]);

	if (full_alias == NULL || fd == -1)
		return;
	fix_extra_spaces(full_alias);
	write(fd, full_alias, strlen(full_alias));
	write(fd, "\n", 1);
	free(full_alias);
	close(fd);
}

/*
** Main function of the alias builtin, display the alias if no arg, and change
** or add alias if there are args in the pipe.
*/
int alias_built(shell_t *shell, pipe_t *pipe)
{
	if (pipe->args[1] == NULL) {
		display_alias(shell, pipe);
		return (0);
	}
	if (pipe->args[2] != NULL && update_alias(shell, pipe) == false)
		create_alias(shell, pipe);
	return (0);
}

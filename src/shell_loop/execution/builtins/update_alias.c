/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Updates the existing aliases.
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"
#include "execution.h"
#include "alias.h"

/*
** Returns the position of the alias match, -1 in case of unexpected error.
*/
static int find_position(char *arg, char **key)
{
	int pos = 0;

	for (pos = 0; key[pos]; pos++) {
		if (strcmp(key[pos], arg) == 0) {
			return (pos);
		}
	}
	return (-1);
}

/*
** Gets the last part of the alias to change and put it in a string.
*/
static char *get_full_alias_value(char **args)
{
	char *value = NULL;
	int size = 0;

	for (int i = 1; args[i]; i++)
		size += strlen(args[i]) + 1;
	value = malloc(sizeof(char) * size);
	value[0] = '\0';
	for (int i = 2; args[i]; i++) {
		value = strcat(value, args[i]);
		value = strcat(value, " ");
	}
	fix_extra_spaces(value);
	return (value);
}

/*
** Re-writes all the aliases in the file.
*/
static void re_write_alias_file(char ***alias, char *path)
{
	int fd = open(path, O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (fd == -1)
		return;
	for (int i = 0; alias[0][i] && alias[1][i]; i++) {
		write(fd, alias[0][i], strlen(alias[0][i]));
		write(fd, " ", 1);
		write(fd, alias[1][i], strlen(alias[1][i]));
		write(fd, "\n", 1);
	}
	close(fd);
}

/*
** The update_specific_alias function that will change and rewrite the alias.
*/
static void update_specific_alias(char **args, char ***alias, char *path)
{
	int pos = find_position(args[1], alias[0]);
	char *full_value = get_full_alias_value(args);

	free(alias[0][pos]);
	free(alias[1][pos]);
	alias[0][pos] = my_strcpy(NULL, args[1]);
	alias[1][pos] = my_strcpy(NULL, full_value);
	if (alias[0][pos] == NULL || alias[1][pos] == NULL) {
		alias[0][pos] = NULL;
		alias[1][pos] = NULL;
		return;
	}
	re_write_alias_file(alias, path);
	free(full_value);
}

/*
** This function will evaluate if there is a match in the aliases and if there
** is one the function will call update_specific_alias. This function will
** change the correct alias's index and re-write all the aliases in the file.
*/
bool update_alias(shell_t *shell, pipe_t *pipe)
{
	char ***alias = get_alias_from_file(shell->paths[0]);

	if (alias == NULL)
		return (false);
	if (alias_match(pipe->args[1], alias[0]) == true) {
		update_specific_alias(pipe->args, alias, shell->paths[0]);
		return (true);
	}
	return (false);
}

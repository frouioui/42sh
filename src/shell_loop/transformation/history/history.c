/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Find out if there is any transformation to do in the given user_input.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mylib.h"
#include "instruction.h"

unsigned int size_history(void)
{
	unsigned int size = 0;
	int fd = open(PATH_HISTORY_FILE, O_RDONLY);
	char *buffer = NULL;

	if (fd == -1)
		return (0);
	while ((buffer = get_next_line(fd)) != NULL) {
		size++;
		free(buffer);
	}
	close(fd);
	return (size);
}

char **get_whole_history(void)
{
	char **history = malloc(sizeof(char *) * (size_history() + 1));
	char *buffer = NULL;
	int i = 0;
	int fd = open(PATH_HISTORY_FILE, O_RDONLY);

	if (history == NULL || fd == -1) {
		my_putstr("We could not find the history file.\n");
		fd != -1 ? close(fd) : 0;
		return (NULL);
	}
	while ((buffer = get_next_line(fd)) != NULL) {
		history[i] = buffer;
		history[i + 1] = NULL;
		i++;
	}
	close(fd);
	return (history);
}

static unsigned int get_target(char *arg)
{
	unsigned int target = my_atoi(arg + 2);

	return (target);
}

static char *concatenate_user_input(char **args)
{
	char *new = NULL;
	int size = 0;
	char *space = strdup(" ");

	for (int i = 0; args[i] != NULL; i++)
		size += my_strlen(args[i]);
	new = malloc(sizeof(char) * (size + 2));
	if (new == NULL)
		return (NULL);
	new[0] = 0;
	for (int cur = 0; args[cur] != NULL; cur++) {
		new = strcat(new, args[cur]);
		new = strcat(new, space);
		if (new == NULL)
			return (NULL);
	}
	free(space);
	my_putstr(args[0]);
	my_putchar('\n');
	return (new);
}

char *get_history(char **args)
{
	char *new = NULL;
	char **history = get_whole_history();
	unsigned int size = size_history();
	unsigned int target = 0;

	if (history == NULL)
		return (NULL);
	if (!(target = get_target(args[0])) || target > size ||
		!(args[0] = strdup(history[size - target]))) {
		free_array_string(history);
		return (NULL);
	}
	if ((new = concatenate_user_input(args)) == NULL) {
		free_array_string(history);
		return (NULL);
	}
	fix_extra_spaces(new);
	return (new);
}

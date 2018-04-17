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
#include "mylib.h"

static unsigned int size_history(void)
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

static char **get_whole_history(void)
{
	char **history = malloc(sizeof(char *) * (size_history() + 1));
	char *buffer = NULL;
	int i = 0;
	int fd = open(PATH_HISTORY_FILE, O_RDONLY);

	if (history == NULL || fd == -1)
		return (NULL);
	while ((buffer = get_next_line(fd)) != NULL) {
		history[i] = buffer;
		history[i + 1] = NULL;
		i++;
	}
	close(fd);
	return (history);
}

static char *get_history_command(char **args)
{
	char **history = get_whole_history();
	char *new = NULL;
	int nb = my_atoi(args[1]);
	int size = size_history();

	if (history == NULL || nb == 0 || nb > size)
		return (NULL);
	new = my_strcpy(NULL, history[size - nb]);
	new[my_strlen(new)] = '\0';
	return (new);
}

char *apply_transformation(bool bonus, char *user_input)
{
	char **args = NULL;
	char *buffer = NULL;

	if (bonus == false)
		return (user_input);
	args = cut_line(user_input);
	buffer = my_strcpy(NULL, user_input);
	if (args == NULL || buffer == NULL)
		return (NULL);
	if (my_strcmp(args[0], "hst") == 0 && args[1] != NULL) {
		user_input = get_history_command(args);
		if (user_input == NULL)
			return (buffer);
	}
	free(buffer);
	free_array_string(args);
	return (user_input);
}

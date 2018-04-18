/*
** EPITECH PROJECT, 2018
** get_execution_filename.c
** File description:
** Get the filepath of an executable
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

static int count_rollback(char *user_input)
{
	int roll_back = 0;
	int i = 0;

	if (user_input[0] == '.' && user_input[1] == '/')
		return (0);
	while (user_input[i] == '.' || user_input[i] == '/') {
		if (user_input[i] == '/')
			roll_back++;
		i++;
	}
	return (roll_back);
}

static void roll_back_path(char *path, int roll_back)
{
	int i = strlen(path);

	while (i > 0 && roll_back != 0) {
		if (path[i] == '/')
			roll_back--;
		path[i] = '\0';
		i--;
	}
}

static int get_file_name(char *exec)
{
	int i = 0;
	int gap = 0;

	if (exec[0] != '.')
		return (-42);
	while (exec[i] == '.' || exec[i] == '/')
		i++;
	gap = i - 1;
	exec[0] = '/';
	while (exec[i] != '\0') {
		exec[i - gap] = exec[i];
		i++;
	}
	exec[i - gap] = '\0';
	return (0);
}

static void *free_file(char *file, char *exec)
{
	free(file);
	free(exec);
	return (NULL);
}

char *get_execution_file_path(char *exec, shell_t *shell)
{
	char *path = strdup(shell->backup->current_pwd);
	char *file = malloc(sizeof(char) * strlen(path) + strlen(exec));
	int roll_back = count_rollback(exec);
	int a = 0;

	a = get_file_name(exec);
	file == NULL ? exit(84) : 0;
	roll_back > 0 && a > -1 ? roll_back_path(path, roll_back) : 0;
	for (int i = 0; a > -1 && path[i]; i++) {
		file[a] = path[i];
		a++;
	}
	free(path);
	a == -42 ? a = 0 : 0;
	for (int i = 0; exec[i] && exec[i] != ' '; a++) {
		file[a] = exec[i];
		file[a + 1] = '\0';
		i++;
	}
	return (access(file, X_OK) == -1 ? free_file(file, exec) : file);
}

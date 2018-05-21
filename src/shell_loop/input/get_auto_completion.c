/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the auto completion of the input and returns it
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"
#include "input.h"

static int adjust_cursor(char *input, int i)
{
	for (int a = 0; a < i; a++) {
		write(1, "\033[1D", 4);
	}
	my_putstr(CLEAR_END_LINE);
	write(1, input, strlen(input));
	return (strlen(input));
}

static char *get_path_match(shell_t *shell, char *input)
{
	char *path = my_get_env(shell->env, "PATH");
	char **seg_path = NULL;
	bool ok = false;

	if (path == NULL)
		return (input);
	seg_path = my_seg_path(path);
	for (int a = 0; ok == false && seg_path && seg_path[a]; a++) {
		input = get_completion_folder(input, seg_path[a], &ok);
		if (ok == true) {
			free_array_string(seg_path);
			free(path);
			return (input);
		}
	}
	seg_path != NULL ? free_array_string(seg_path) : 0;
	path != NULL ? free(path) : 0;
	return (input);
}

static char *get_math_current_folder(shell_t *shell, char *input, bool *change)
{
	char *pwd = my_get_env(shell->env, "PWD");
	bool ok = false;

	if (pwd == NULL)
		return (input);
	input = get_completion_folder(input, pwd, &ok);
	if (ok == true)
		*change = true;
	free(pwd);
	return (input);
}

char *get_auto_completion(char *input, int c, int *i, shell_t *shell)
{
	bool change = false;
	char *copy_input = NULL;
	char *new_input = NULL;

	if (c != '\t' || strlen(input) < 2)
		return (input);
	copy_input = strdup(input);
	new_input = cut_last_input(input);
	if (new_input == NULL || strlen(new_input) == 0) {
		free(input);
		new_input != NULL ? free(new_input) : 0;
		return (copy_input);
	}
	new_input = get_math_current_folder(shell, new_input, &change);
	if (change == false) {
		new_input = get_path_match(shell, new_input);
	}
	input = restore_input_autocompletion(input, new_input);
	*i = adjust_cursor(input, *i);
	return (input);
}

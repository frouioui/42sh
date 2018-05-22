/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on get globbing arguments
*/

#include <criterion/criterion.h>
#include "globbing.h"
#include "mylib.h"

static void free_array(char **array)
{
	if (!array)
		return;
	for (int i = 0; array[i]; i += 1)
		free(array[i]);
	free(array);
}

Test(get_args, glob)
{
	pipe_t **pipe = malloc(sizeof(*pipe) * 2);
	char **wait = cut_line("ls bonus tests lib");

	if (!pipe)
		return;
	pipe[0] = malloc(sizeof(**pipe));
	pipe[0]->args = cut_line("ls *s ?ib");
	pipe[1] = NULL;
	get_glob_args(pipe);
	for (int i = 0; pipe[0]->args[i]; i += 1)
		cr_assert_str_eq(pipe[0]->args[i], wait[i]);
	free_array(pipe[0]->args);
	free_array(wait);
	free(pipe[0]);
	free(pipe);
}

Test(get_args, no_glob)
{
	pipe_t **pipe = malloc(sizeof(*pipe) * 2);
	char **wait = cut_line("ls *to");

	if (!pipe)
		return;
	pipe[0] = malloc(sizeof(**pipe));
	pipe[0]->args = cut_line("ls *to");
	pipe[1] = NULL;
	get_glob_args(pipe);
	for (int i = 0; pipe[0]->args[i]; i += 1)
		cr_assert_str_eq(pipe[0]->args[i], wait[i]);
	free_array(pipe[0]->args);
	free_array(wait);
	free(pipe[0]);
	free(pipe);
}

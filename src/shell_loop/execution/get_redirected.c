/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Clear the pipe's substrings, and get the file name of the redirection
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "instruction.h"
#include "mylib.h"

static char *cut_filename(char *instruction, redirect_t redirect)
{
	char *filename = malloc(sizeof(char) * my_strlen(instruction));
	int i = 0;
	int a = 0;

	if (filename == NULL)
		return (NULL);
	while (REDIRECT_CHAR(instruction[i]) == 0 && instruction[i])
		i++;
	while (REDIRECT_CHAR(instruction[i]) && instruction[i])
		i++;
	redirect == STDERR_DOUBLE || redirect == STDERR_SIMPLE ? i++ : 0;
	while (SPACE_TAB(instruction[i]) && instruction[i])
		i++;
	while (instruction[i] && SPACE_TAB(instruction[i]) == 0) {
		filename[a] = instruction[i];
		i++;
		a++;
		filename[a] = '\0';
	}
	return (filename);
}

static void clear_redirected_pipe(char *instruction)
{
	int i = 0;

	while (instruction[i] && REDIRECT_CHAR(instruction[i]) == 0)
		i++;
	instruction[i] = '\0';
}

char *get_redirect_filename(pipe_t *pipe)
{
	char *file = cut_filename(pipe->full_instruction, pipe->type_redirect);

	if (file == NULL)
		return (file);
	free_array_string(pipe->args);
	clear_redirected_pipe(pipe->full_instruction);
	pipe->args = cut_line(pipe->full_instruction);
	return (file);
}

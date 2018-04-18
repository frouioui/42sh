/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Get the whole pipe instructions
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static unsigned int get_args_pipe(pipe_t **pipe, char **env)
{
	int a = 0;

	for (unsigned int i = 0; pipe[i]; i++) {
		pipe[i]->args = cut_line(pipe[i]->full_instruction);
		if (pipe[i]->args == NULL)
			return (FAILURE);
		check_env_variable(pipe[i]->args, env);
	}
	return (SUCCESS);
}

static void clean_next_char(pipe_t **pipe, int i, int a)
{
	pipe[i]->full_instruction[a + 1] = '\0';
	pipe[i]->full_instruction[a + 2] = '\0';
}

static unsigned int get_full_pipe(pipe_t **pipe, instruction_t *inst)
{
	unsigned int j = 0;

	for (unsigned int i = 0; i < inst->number_of_pipe; i++) {
		pipe[i]->full_instruction = malloc(sizeof(char) *
		(strlen(inst->full_instruction) + 2));
		if (pipe[i]->full_instruction == NULL)
			return (FAILURE);
		for (int a = 0; inst->full_instruction[j] &&
		inst->full_instruction[j] != PIPE_SEPARATOR; a++) {
			pipe[i]->full_instruction[a] =
			inst->full_instruction[j];
			clean_next_char(pipe, i, a);
			j++;
		}
		fix_extra_spaces(pipe[i]->full_instruction);
		for (j; inst->full_instruction[j] &&
		inst->full_instruction[j] == ' '; j++);
		inst->full_instruction[j] == '|' ? j++ : 0;
	}
	return (SUCCESS);
}

pipe_t **get_pipe(bool bonus, instruction_t *instruction, char **env)
{
	pipe_t **pipe = malloc(sizeof(pipe_t *) *
	(instruction->number_of_pipe + 1));

	if (pipe == NULL)
		return (NULL);
	for (unsigned int i = 0; i < instruction->number_of_pipe; i++) {
		pipe[i] = malloc(sizeof(pipe_t));
		if (pipe[i] == NULL)
			return (NULL);
		pipe[i]->valid = true;
		pipe[i + 1] = NULL;
	}
	if (get_full_pipe(pipe, instruction) == FAILURE)
		return (NULL);
	if (get_args_pipe(pipe, env) == FAILURE)
		return (NULL);
	if (get_redirect(bonus, pipe, instruction->number_of_pipe) == FAILURE)
		return (NULL);
	return (pipe);
}

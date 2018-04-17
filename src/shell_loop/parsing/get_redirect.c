/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Get the whole pipe instructions
*/

#include <stdlib.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static void check_after_redirect(pipe_t *pipe, char *inst, int *i)
{
	while (inst[*i] && SPACE_TAB(inst[*i]))
		(*i)++;
	if (inst[*i] == '\0' || REDIRECT_CHAR(inst[*i])) {
		pipe->valid = false;
		pipe->error = INVALID_REDIRECT_NAME;
		pipe->type_redirect = EMPTY_REDIR;
		pipe->redirect = false;
		return;
	}
	while (inst[*i] && REDIRECT_CHAR(inst[*i]) == false)
		(*i)++;
	if (inst[*i] != '\0') {
		pipe->valid = false;
		pipe->error = AMBIGUOUS_REDIRECT;
		pipe->type_redirect = EMPTY_REDIR;
		pipe->redirect = false;
	} else {
		pipe->redirect = true;
	}
}

void check_stderr_redirect(pipe_t *pipe, char *inst, int *i)
{
	if (inst[*i + 1] == '>' && inst[*i + 2] == '2' &&
		SPACE_TAB(inst[*i + 3])) {
		pipe->type_redirect = STDERR_DOUBLE;
		*i = *i + 3;
	} else if (inst[*i + 1] == '2' && SPACE_TAB(inst[*i + 2])) {
		pipe->type_redirect = STDERR_SIMPLE;
		*i = *i + 2;
	}
}

static void scan_redirect(bool bonus, pipe_t *pipe, char *inst, int *i)
{
	if (inst[*i] == '>') {
		if (inst[*i + 1] == '>' && SPACE_TAB(inst[*i + 2])) {
			pipe->type_redirect = STDOUT_DOUBLE;
			*i = *i + 2;
		} else if (SPACE_TAB(inst[*i + 1])) {
			pipe->type_redirect = STDOUT_SIMPLE;
			*i = *i + 1;
		}
		bonus == true ? check_stderr_redirect(pipe, inst, i) : 0;
	} else if (inst[*i] == '<') {
		if (inst[*i + 1] == '<' && SPACE_TAB(inst[*i + 2])) {
			pipe->type_redirect = STDIN_DOUBLE;
			*i = *i + 2;
		} else if (SPACE_TAB(inst[*i + 1])) {
			pipe->type_redirect = STDIN_SIMPLE;
			*i = *i + 1;
		}
	}
	check_after_redirect(pipe, inst, i);
}

unsigned int analyse_redirect(bool bonus, pipe_t *pipe)
{
	for (int i = 0; pipe->full_instruction[i] && pipe->valid; i++) {
		if (REDIRECT_CHAR(pipe->full_instruction[i])) {
			scan_redirect(bonus, pipe, pipe->full_instruction, &i);
		}
	}
	return (0);
}

unsigned int get_redirect(bool bonus, pipe_t **pipe, unsigned int nb_of_pipe)
{
	for (unsigned int i = 0; i < nb_of_pipe; i++) {
		pipe[i]->redirect = false;
		analyse_redirect(bonus, pipe[i]);
	}
	return (SUCCESS);
}

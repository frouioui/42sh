/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Find out if there is any transformation to do in the given user_input.
*/

#include <stdlib.h>
#include <string.h>
#include "alias.h"
#include "instruction.h"
#include "mylib.h"

char *apply_transformation(bool bonus, char *user_input)
{
	char **args = NULL;
	char *buffer = NULL;

	if (bonus == false)
		return (user_input);
	if (!(args = cut_line(user_input)) || !(buffer = strdup(user_input)))
		return (NULL);
	if (HISTORY_FLAG(args[0])) {
		user_input = get_history(args);
		if (user_input == NULL)
			return (buffer);
	}
	user_input = get_alias(args, user_input);
	free(buffer);
	free_array_string(args);
	return (user_input);
}

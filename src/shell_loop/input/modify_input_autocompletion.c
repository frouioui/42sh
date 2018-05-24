/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Cut or restore the input after and before the auto completion
*/

#include <stdlib.h>
#include <string.h>

char *cut_last_input(char *input)
{
	int i = strlen(input) - 1;
	int a = 0;
	char *new = NULL;

	while (i > 0 && input[i] && input[i] != ' ')
		i--;
	if (input[i] == ' ')
		i++;
	a = i;
	new = malloc(sizeof(char) * (strlen(input) - i + 5));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	for (int j = 0; input[i]; i++, j++) {
		new[j] = input[i];
		new[j + 1] = '\0';
	}
	input[a] = '\0';
	return (new);
}

static char *concate_restore(char *input, char *new)
{
	char *str = malloc(sizeof(char) * (strlen(input) + strlen(new) + 1));
	int i = 0;

	if (new == NULL)
		return (NULL);
	str[i] = '\0';
	for (int a = 0; input && input[a]; a++) {
		str[i] = input[a];
		str[i + 1] = '\0';
		i++;
	}
	for (int a = 0; new && new[a]; a++) {
		str[i] = new[a];
		str[i + 1] = '\0';
		i++;
	}
	return (str);
}

char *restore_input_autocompletion(char *input, char *new)
{
	char *new_input = NULL;

	new_input = concate_restore(input, new);
	if (new_input == NULL) {
		return (input);
	} else {
		free(input);
		free(new);
	}
	return (new_input);
}

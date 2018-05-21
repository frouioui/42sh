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

char *restore_input_autocompletion(char *input, char *new)
{
	char *new_input = strcat(input, new);

	if (new_input == NULL) {
		return (input);
	}
	return (new_input);
}

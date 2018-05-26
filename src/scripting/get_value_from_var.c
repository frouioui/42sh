/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get value from local variables
*/

#include "execution.h"
#include "script.h"

char *sup_value_symbol(char *var)
{
	char *new = malloc(sizeof(*new) * (strlen(var) + 1));
	int i = 0;

	if (!new)
		return (NULL);
	for (int j = 1; var[j] != '\0'; i += 1, j += 1)
		new[i] = var[j];
	new[i] = '\0';
	free(var);
	return (new);
}

int get_value_from_var(shell_t *shell, char *var)
{
	int line = get_pos_key(var, shell->local);
	char *tmp = NULL;
	int value = 0;
	int index = 0;
	int j = 0;

	if (line == -1)
		return (-1);
	tmp = strdup(shell->local[line]);
	for (int i = index; tmp[i] != '\0' && tmp[i] != '\t'; i++, index ++);
	for (j = 0; tmp[index] != '\0'; j ++, index ++)
		tmp[j] = tmp[index];
	tmp[j] = '\0';
	value = atoi(tmp);
	free(tmp);
	return (value);
}

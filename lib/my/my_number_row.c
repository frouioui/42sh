/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Counts the number of row in a char ** variable
*/

unsigned int my_number_row(char **array)
{
	int size = 0;

	while (array[size])
		size++;
	return (size);
}

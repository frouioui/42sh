/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Create nb - 1 pipes, return NULL if error.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int **create_pipe(int nb)
{
	int **fd = malloc(sizeof(int *) * (nb));

	if (fd == NULL)
		return (NULL);
	for (int i = 0; i < nb - 1; i++) {
		fd[i] = malloc(sizeof(int) * 2);
		if (fd[i] == NULL)
			return (NULL);
		fd[i + 1] = NULL;
		if (pipe(fd[i]) == -1) {
			perror("pipe");
			exit(84);
			return (NULL);
		}
	}
	return (fd);
}

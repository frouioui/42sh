/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Returns a char ** with the segmented path
*/

#include <stdlib.h>

static int get_nb_seg(char *path)
{
	int nb = 0;
	int i = 0;

	while (path && path[i]) {
		if (path[i] == ':')
			nb++;
		i++;
	}
	if (path && path[i] == '\0')
		nb++;
	return (nb);
}

static unsigned int size_next_path(char *path)
{
	unsigned int i = 0;

	while (path && path[i] && path[i] != ':') {
		i++;
	}
	return (i + 1);
}

static char *get_seg_path(char *path, int *a)
{
	char *seg = malloc(sizeof(char) * size_next_path(path + *a));
	int i = 0;

	if (seg == NULL)
		return (NULL);
	seg[0] = '\0';
	while (path && path[*a] && path[*a] != ':') {
		seg[i] = path[*a];
		i++;
		(*a)++;
		seg[i] = '\0';
	}
	if (path && path[*a] && path[*a] == ':')
		(*a)++;
	return (seg);
}

char **my_seg_path(char *path)
{
	char **seg_path = NULL;
	int nb_seg = get_nb_seg(path);
	int a = 0;

	seg_path = malloc(sizeof(char *) * (nb_seg + 1));
	if (seg_path == NULL)
		return (NULL);
	for (int i = 0; i < nb_seg && path[a]; i++) {
		seg_path[i] = get_seg_path(path, &a);
		seg_path[i + 1] = NULL;
	}
	return (seg_path);
}

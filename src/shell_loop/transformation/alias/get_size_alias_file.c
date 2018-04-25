/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** File of the get_size_alias_file function, returns the number of line.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "alias.h"
#include "mylib.h"

int get_size_alias_file(char *home)
{
	int fd = open(home, O_RDONLY | O_CREAT |
	O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	unsigned int size = 0;
	char c = 0;

	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) == 1) {
		if (c == '\n')
			size++;
	}
	close(fd);
	return (size);
}

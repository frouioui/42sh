/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the full alias from the .alias file.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "alias.h"
#include "mylib.h"

static char **read_alias_file(void)
{
	int size = get_size_alias_file();
	unsigned int i = 0;
	char **content = NULL;
	int fd = open(ALIAS_FILE, O_RDONLY | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (size < 0 || !(content = malloc(sizeof(char *) * (size + 1))) ||
	fd == -1)
		return (NULL);
	while ((content[i] = get_next_line(fd)) != NULL)
		i++;
	content[i] = NULL;
	return (content);
}

static char **get_value_alias(char **value, char **content)
{
	int a = 0;

	value = malloc(sizeof(char) * (my_number_row(content) + 2));
	if (value == NULL)
		return (NULL);
	for (unsigned int i = 0; content[i]; i++) {
		value[i] = malloc(sizeof(char) * (strlen(content[i]) + 1));
		if (value[i] == NULL)
			return (value);
		for (a = 0; content[i][a] && SPACE_TAB(content[i][a]); a++);
		for (a = a; content[i][a] && !SPACE_TAB(content[i][a]); a++);
		for (a = a; content[i][a] && SPACE_TAB(content[i][a]); a++);
		for (int j = 0; content[i][a]; a++)
			value[i][j++] = content[i][a];
		value[i][a] = '\0';
	}
	return (value);
}

static char **get_key_alias(char **key, char **content)
{
	int a = 0;
	int j = 0;

	key = malloc(sizeof(char) * (my_number_row(content) + 2));
	if (key == NULL)
		return (NULL);
	for (unsigned int i = 0; content[i]; i++) {
		key[i] = malloc(sizeof(char) * (strlen(content[i]) + 1));
		if (key[i] == NULL)
			return (key);
		for (a = 0; content[i][a] && SPACE_TAB(content[i][a]); a++);
		for (j = 0; content[i][a] && !SPACE_TAB(content[i][a]); a++)
			key[i][j++] = content[i][a];
		key[i][j] = '\0';
	}
	return (key);
}

char ***get_alias_from_file(void)
{
	char ***alias = malloc(sizeof(char **) * 3);
	char **content = read_alias_file();

	if (alias == NULL || content == NULL)
		return (NULL);

	alias[0] = get_key_alias(alias[0], content);
	alias[1] = get_value_alias(alias[1], content);
	alias[2] = NULL;
	free_array_string(content);
	return (alias);
}

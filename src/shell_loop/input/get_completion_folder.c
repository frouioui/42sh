/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Returns the completed input with the given folder
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

static bool filename_input_match(char *input, char *filename)
{
	for (int i = 0; filename[i] && input[i]; i++) {
		if (filename[i] != input[i])
			return (false);
	}
	return (true);
}

char *get_completion_folder(char *input, char *folder, bool *ok)
{
	DIR *dir = opendir(folder);
	struct dirent *read_files = NULL;

	if (dir == NULL)
		return (input);
	while ((read_files = readdir(dir)) != NULL) {
		if (strlen(read_files->d_name) >= strlen(input)
		&& filename_input_match(input, read_files->d_name) == true) {
			free(input);
			input = strdup(read_files->d_name);
			*ok = true;
			closedir(dir);
			return (input);
		}
	}
	closedir(dir);
	return (input);
}

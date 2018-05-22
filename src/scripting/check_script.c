/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check script file
*/

#include "script.h"
#include <unistd.h>
#include <string.h>

bool check_script_shebang(char *path)
{
	FILE *fd = fopen(path, "r");
	size_t n = 0;
	char *buf = NULL;

	if (!fd)
		return (false);
	if (getline(&buf, &n, fd) == -1) {
		fclose(fd);
		return (false);
	}
	if (buf && !strncmp(buf, "#!", 2)) {
		free(buf);
		fclose(fd);
		return (true);
	}
	if (buf)
		free(buf);
	fclose(fd);
	return (false);
}

bool check_script_name(char *path)
{
	char *tmp = malloc(sizeof(*tmp) * (strlen(path) + 1));
	int j = 0;

	if (!tmp)
		return (false);
	for (int i = strlen(path) - 1; SH_CHAR(path[i]); i -= 1) {
		tmp[j] = path[i];
		j += 1;
	}
	tmp[j] = '\0';
	if (!strcmp(tmp, "hs.")) {
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}

bool check_script_access(char *path)
{
	if (access(path, R_OK) == -1) {
		write(1, path, strlen(path));
		write(1, ": Command not found.\n", 21);
		return (false);
	}
	else if (access(path, X_OK) == -1) {
		write(1, path, strlen(path));
		write(1, ": Permission denied.\n", 21);
		return (false);
	}
	return (true);
}

bool check_script(char *path)
{
	if (!path)
		return (false);
	if (!check_script_name(path))
		return (false);
	if (!check_script_access(path))
		return (false);
	if (!check_script_shebang(path))
		return (false);
	return (true);
}

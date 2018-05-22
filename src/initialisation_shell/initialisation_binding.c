/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Init functions of the binding structure
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

static bool read_binding_map(binding_t *binding, char *file)
{
	int fd = open(file, O_RDONLY);
	int res = 0;

	if (fd == -1)
		return (false);
	res = read(fd, binding, sizeof(binding_t));
	close(fd);
	if (res != sizeof(binding_t))
		return (false);
	return (true);
}

static void set_default_values_binding(binding_t *binding)
{
	binding->clear = DEFAULT_CLEAR_BINDING;
	binding->exit = DEFAULT_EXIT_BINDING;
	binding->up = DEFAULT_UP_BINDING;
	binding->down = DEFAULT_DOWN_BINDING;
	binding->right = DEFAULT_RIGHT_BINDING;
	binding->left = DEFAULT_LEFT_BINDING;
	binding->end = DEFAULT_END_BINDING;
	binding->begin = DEFAULT_BEGIN_BINDING;
	binding->suppr = DEFAULT_SUPPR_BINDING;
}

static bool backup_binding_map(binding_t *binding, shell_t *shell)
{
	int fd = open(shell->paths[2], O_WRONLY | O_CREAT | O_TRUNC, 00644);

	if (fd == -1)
		return (false);
	set_default_values_binding(binding);
	if (write(fd, binding, sizeof(binding_t)) == -1) {
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

binding_t *init_bindings(shell_t *shell)
{
	binding_t *binding = malloc(sizeof(binding_t));

	if (binding == NULL)
		return (NULL);
	binding->code = 0;
	if (read_binding_map(binding, shell->paths[2]) == false) {
		if (backup_binding_map(binding, shell) == false) {
			free(binding);
			return (NULL);
		}
	}
	return (binding);
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Tells whether or not an input is binded
*/

#include <stdbool.h>
#include "shell.h"

bool is_key_binding(shell_t *shell)
{
	if (shell->binding->code == shell->binding->clear ||
	shell->binding->code == shell->binding->exit) {
		return (true);
	}
	return (false);
}

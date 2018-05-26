/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** florent.poinsard@epitech.eu
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

void put_new_old_pwd(shell_t *shell, char *buffer)
{
	unsigned int pos_old_pwd = get_line_env(shell->env, "OLDPWD");
	char name[] = "OLDPWD=";
	int j = 0;

	if (buffer == NULL)
		return;
	shell->env[pos_old_pwd] = malloc(sizeof(char) *
		(strlen(buffer) + 8));
	if (shell->env[pos_old_pwd] == NULL)
		exit(84);
	for (int i = 0; name[i]; i++) {
		shell->env[pos_old_pwd][j] = name[i];
		j++;
	}
	for (int i = 0; buffer && buffer[i]; i++) {
		shell->env[pos_old_pwd][j] = buffer[i];
		j++;
	}
	shell->env[pos_old_pwd][j] = '\0';
}

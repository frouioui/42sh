/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Functions that display the prompt -> maybe add bonuses for personalisation
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

char *get_current_user(shell_t *shell)
{
	return (my_get_env(shell->env, "USER"));
}

char *get_current_host(shell_t *shell)
{
	return (my_get_env(shell->env, "HOSTNAME"));
}

char *get_current_folder(shell_t *shell)
{
	char *pwd = my_get_env(shell->env, "PWD");
	char *folder = NULL;
	int i = 0;
	int a = 1;

	pwd != NULL ? i = my_strlen(pwd) : 0;
	while (pwd != NULL && pwd[i - 1] != '/' && pwd[i - 1]) {
		a++;
		i--;
	}
	pwd != NULL ? folder = malloc(sizeof(char) * a) : 0;
	if (pwd != NULL && folder == NULL)
		exit(84);
	for (a = 0; pwd != NULL && pwd[i] != '\0'; i++) {
		folder[a] = pwd[i];
		a++;
	}
	pwd != NULL ? folder[a] = '\0' : 0;
	free(pwd);
	return (folder);
}

int display_prompt(shell_t *shell)
{
	char *user = get_current_user(shell);
	char *folder = get_current_folder(shell);
	char *host = get_current_host(shell);

	if (shell->bonus == false) {
		my_putstr("[");
		user != NULL ? my_putstr(user) : my_putstr("anonyme");
		my_putstr("@");
		host != NULL ? my_putstr(host) : my_putstr("localhost");
		my_putstr("]");
		my_putstr(" -> ");
		folder != NULL ? my_putstr(folder) : 0;
		my_putstr(" $ ");
	} else {
		display_bonus_prompt(shell->code, user, folder, host);
	}
	folder != NULL ? free(folder) : 0;
	folder != NULL ? free(host) : 0;
	folder != NULL ? free(user) : 0;
	return (1);
}

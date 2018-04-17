/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Display the prompt only if bonus mode is true
*/

#include <stdlib.h>
#include "colors.h"
#include "mylib.h"

static void display_user(char *user)
{
	my_putstr(WHITE);
	my_putchar('[');
	my_putstr(GREEN);
	my_putstr(user != NULL ? user : "anonyme");
	my_putstr(WHITE);
}

static void display_hostname(char *host)
{
	my_putchar('@');
	my_putstr(CYAN);
	my_putstr(host != NULL ? host : "localhost");
	my_putstr(WHITE);
	my_putstr("] -> ");
}

static void display_folder(char *folder)
{
	my_putstr(YELLOW);
	my_putstr(folder != NULL ? folder : ".");
	my_putstr(" ");
}

static void display_return(int code)
{
	if (code == 0) {
		my_putstr(GREEN);
		my_putstr(" $ ");
	} else {
		my_putstr(RED);
		my_putstr(" $ ");
	}
}

void display_bonus_prompt(int code, char *user, char *folder, char *host)
{
	display_user(user);
	display_hostname(host);
	display_folder(folder);
	display_return(code);
	my_putstr(WHITE);
}

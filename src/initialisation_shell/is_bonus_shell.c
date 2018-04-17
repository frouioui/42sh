/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Detects if the given program is on bonus mode (true) or not (false)
*/

#include <stdbool.h>
#include "mylib.h"

bool is_bonus(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	if (my_strcmp(argv[1], "--bonus") == 0)
		return (true);
	return (false);
}

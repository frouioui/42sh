/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Destroys the pointers used in the cd_built function
*/

#include <stdlib.h>

int destroy_cd_resources(char *folder)
{
	free(folder);
	return (0);
}

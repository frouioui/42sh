/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** florian.davasse@epitech.eu
*/

#include "mylib.h"

bool my_ischar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (true);
	return (false);
}

/*
** EPITECH PROJECT, 2017
** my_ischar.c
** File description:
** florian.davasse@epitech.eu
*/

#include "mylib.h"

bool my_ischar(char c)
{
	if ((c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z'))
		return (true);
	return (false);
}

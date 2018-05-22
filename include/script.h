/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file of the scripting functions
*/

#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <stdbool.h>
#include <stdlib.h>

#define SH_CHAR(c) (c == '.' || c == 's' || c == 'h')

bool check_script(char *);
bool check_script_access(char *);
bool check_script_name(char *);
bool check_script_shebang(char *);

#endif /* !CRIPTING_H */

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file of all the alias function and macros. Part of parsing include.
*/

#ifndef ALIAS_H
#define ALIAS_H

#define ALIAS_FILE "/.alias"

char *get_alias(char **, char *, char *);
char ***get_alias_from_file(char *);
int get_size_alias_file(char *);
char *get_alias_match(char **, char *, char ***);

#endif /* end of include guard: ALIAS_H */

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file of the globbings structures and functions.
*/

#ifndef GLOBBING_H
#define GLOBBING_H

#include <glob.h>
#include "instruction.h"

#define GLOB(c) (c == '*' || c == '?' || c == '[' || c == ']')

typedef struct arg_list_s {
	char *arg;
	struct arg_list_s *next;
} args_list_t;

// Function to manage globbings
int get_glob_args(pipe_t **);
int add_path_in_pipe(args_list_t *, pipe_t *);
int search_glob_args(args_list_t *, args_list_t **);

// Linked list management
args_list_t *built_list(char **);
args_list_t *add_new_path(args_list_t *, args_list_t *, args_list_t **);
void free_args_list(args_list_t *);

#endif /* !GLOBBING_H */

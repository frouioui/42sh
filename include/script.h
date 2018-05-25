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
#include <stdio.h>
#include "shell.h"

#define SH_CHAR(c) (c == '.' || c == 's' || c == 'h')
#define NB_COND (6)

/* --  Structures definition --- */
typedef enum keyword_e {
	EMPTY,
	IF,
	ELSE,
	ELSIF,
	WHILE,
	FOREACH,
	WHICH,
	WHERE
} keyword_t;

typedef struct cond_script_s {
	keyword_t key;
	char *condition;
	char *command;
	bool end;
} cond_t;

/* --- Check script file --- */
bool check_script(char *);
bool check_script_access(char *);
bool check_script_name(char *);
bool check_script_shebang(char *);

/* --- Script running --- */
char *get_valid_line(FILE *, shell_t *);
char *run_script(shell_t *, FILE *);
FILE *open_script(char *, shell_t *);
bool fill_cond(cond_t *, char *, char **);
int search_keyword(cond_t *, char *);

/* --- Initialization --- */
cond_t *init_conditional_line(void);

/* -- Resources destruction --- */
void free_cond_line(cond_t *);

#endif /* !CRIPTING_H */

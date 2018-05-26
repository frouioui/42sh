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
#define NB_OPE (6)

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

typedef struct ope_s {
	char *ope;
	int (*redir_comp)(shell_t *, cond_t *, char **, char **);
} ope_t;

typedef struct cond_redir_s {
	keyword_t key;
	char *(*redir_cond)(shell_t *, cond_t *, FILE *);
} cond_redir_t;

/* --- Check script file --- */
bool check_script(char *);
bool check_script_access(char *);
bool check_script_name(char *);
bool check_script_shebang(char *);

/* --- Script running --- */
bool fill_cond(cond_t *, char *, char **);
char *condition_management(shell_t *, cond_t *, FILE *);
char *get_valid_line(FILE *, shell_t *);
char *if_management(shell_t *, cond_t *, FILE *);
char *run_script(shell_t *, FILE *);
FILE *open_script(char *, shell_t *);
int get_value_from_var(shell_t *, char *);
int search_keyword(cond_t *, char *);
void print_error_syntax(cond_t *);
void print_error_var(char *, char *, int, int);

/* --- Conditions management --- */
char *sup_value_symbol(char *);
int check_script_condition(shell_t *, cond_t *);
int op_diff(shell_t *, cond_t *, char **, char **);
int op_equal(shell_t *, cond_t *, char **, char **);
int op_inf(shell_t *, cond_t *, char **, char **);
int op_inf_eq(shell_t *, cond_t *, char **, char **);
int op_sup(shell_t *, cond_t *, char **, char **);
int op_sup_eq(shell_t *, cond_t *, char **, char **);

/* --- Initialization --- */
cond_t *init_conditional_line(void);

/* -- Resources destruction --- */
void free_cond_line(cond_t *);

#endif /* !CRIPTING_H */

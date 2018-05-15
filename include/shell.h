/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the main structures and functions.
*/

#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "instruction.h"
#include "mylib.h"

#define PATH_HISTORY_FILE ".history"

#define SUCCESS 0
#define SKIP 21
#define FAILURE 84


typedef struct backup_s {
	char *user;
	char *path;
	char *home;
	char *current_pwd;
} backup_t;

typedef enum state_s {
	OK,
	EXIT,
	ERROR_84,
	ERROR_1
} state_t;

typedef struct binding_s {
	int code;
	int clear;
	int exit;
} binding_t;

typedef struct shell_s {
	char **env;
	char **paths;
	int code;
	backup_t *backup;
	command_line_t *command_line;
	binding_t *binding;
	state_t state;
	bool bonus;
	bool term;
	bool prompt;
} shell_t;

char **copy_environement(char **);
void free_array_string(char **);
void display_bonus_prompt(int, char *, char *, char *);
void update_backup(shell_t *);
bool is_bonus(int, char **);
int display_prompt(shell_t *shell);
int check_args(int);
int destroy_shell(shell_t *);
int find_option_env(char **env, char *str);
int find_separator_env(char *str);
unsigned int shell_loop(shell_t *);
unsigned int redirect_loop(shell_t *, char *);

/* --- basic init functions --- */
shell_t *initialisation_shell(int, char **, char **);
backup_t *initialisation_backup(char **);
char **init_paths(char **);

/* --- history function --- */
void write_command_history(command_line_t *, char **);

/* --- input handling functions --- */
bool init_terminal(shell_t *);
char *get_input(shell_t *, int);

/* --- binding functions / redirection struct / macros --- */
binding_t *init_bindings(shell_t *shell);
bool is_key_binding(shell_t *shell);
void execute_key_binding(shell_t *shell, binding_t *binding);

typedef struct redirect_binding_s {
	int code;
	void (*bind)(shell_t *);
} redir_binding_t;

#ifndef BINDING_DEFAULT_H
#define BINDING_DEFAULT_H

#define NB_BIND 2
#define DEFAULT_EXIT_BINDING 16
#define DEFAULT_CLEAR_BINDING 12
#define EOT 4
#define DEL 127
#define BACKSPACE 8

#endif

#endif /* end of include guard: SHELL_H */

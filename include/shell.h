/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file of the main structures and functions.
*/

#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
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
	int up;
	int down;
	int right;
	int left;
	int end;
	int begin;
	int suppr;
} binding_t;

typedef struct terminal_s {
	struct termios old;
	bool term;
} terminal_t;

typedef struct shell_s {
	char **env;
	char **local;
	char **paths;
	int code;
	backup_t *backup;
	command_line_t *command_line;
	binding_t *binding;
	state_t state;
	terminal_t terminal;
	bool bonus;
	bool prompt;
} shell_t;

char **copy_environement(char **);
void free_array_string(char **);
void display_bonus_prompt(int, char *, char *, char *);
void update_backup(shell_t *);
bool init_terminal(shell_t *);
bool is_bonus(int, char **);
int display_prompt(shell_t *);
int check_args(int);
int destroy_shell(shell_t *);
int find_option_env(char **, char *);
int find_separator_env(char *);
unsigned int shell_loop(shell_t *);
unsigned int redirect_loop(shell_t *, char *);
char **init_local(void);

/* --- basic init functions --- */
shell_t *initialisation_shell(int, char **, char **);
backup_t *initialisation_backup(char **);
char **init_paths(char **);

/* --- history function --- */
void write_command_history(command_line_t *, char **);

/* --- binding functions / redirection struct / macros --- */
binding_t *init_bindings(shell_t *shell);

typedef struct redirect_binding_s {
	int code;
	void (*bind)(shell_t *);
} redir_binding_t;

#ifndef BINDING_DEFAULT_H
#define BINDING_DEFAULT_H

#define DEFAULT_EXIT_BINDING 16
#define DEFAULT_CLEAR_BINDING 12
#define DEFAULT_UP_BINDING 4283163
#define DEFAULT_DOWN_BINDING 4348699
#define DEFAULT_RIGHT_BINDING 4414235
#define DEFAULT_LEFT_BINDING 4479771
#define DEFAULT_END_BINDING 4610843
#define DEFAULT_BEGIN_BINDING 4741915
#define DEFAULT_SUPPR_BINDING 2117294875
#define EOT 4
#define DEL 127
#define BACKSPACE 8

#endif

#endif /* end of include guard: SHELL_H */

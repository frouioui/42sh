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
#include <sys/types.h>
#include "instruction.h"
#include "process_gestion.h"
#include "mylib.h"

#define PATH_HISTORY_FILE ".history"

#define SUCCESS (0)
#define SKIP (21)
#define FAILURE (84)

// jobs control
#define CHANGED_SIGNAL (2)

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

typedef struct shell_s {
	char **env;
	backup_t *backup;
	command_line_t *command_line;
	state_t state;
	int code;
	bool bonus;
	char **paths;
	running_process_t *process;
} shell_t;

int check_args(int);
char **copy_environement(char **);
shell_t *initialisation_shell(int, char **, char **);
char **copy_environement(char **);
backup_t *initialisation_backup(char **);
unsigned int shell_loop(shell_t *);
unsigned int redirect_loop(shell_t *, char *);
int display_prompt(shell_t *shell);
void free_array_string(char **);
void update_backup(shell_t *);
int destroy_shell(shell_t *);
void write_command_history(command_line_t *, char **);
bool is_bonus(int, char **);
void display_bonus_prompt(int, char *, char *, char *);
int find_option_env(char **env, char *str);
int find_separator_env(char *str);
char **init_paths(char **);
// Process Gestion
bool get_process(struct sigaction *saves[2], pid_t pid, shell_t *shell,
pipe_t pipe);
int fg_built(shell_t * /*shell*/, pipe_t * /*pipe*/);


#endif /* end of include guard: SHELL_H */

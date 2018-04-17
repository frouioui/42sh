/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the execution functions group
*/

#ifndef EXECUTION_H
#define EXECUTION_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"
#include "instruction.h"

#define NB_BUILTIN 5

/* --- functions redirection sturcture --- */
typedef struct redirect_flag_s {
	char *name;
	int (*built)(shell_t *, pipe_t *);
} redir_builtins_t;

/* --- standard commands functions --- */
unsigned int execute_command(shell_t *, command_line_t *);
void multiple_execution(shell_t *, instruction_t *);
void simple_execution(shell_t *, instruction_t *);
unsigned int execute_command(shell_t *, command_line_t *);
int **create_pipe(int);
void check_end_exec(int);
void exec_pipe(shell_t *, instruction_t *, int **, pid_t);
int dup_my_pipe(shell_t *, instruction_t *, unsigned int, int **);
void redirect_pipe(bool, pipe_t *);
void display_error_execution(char *);
char *get_path_exec(pipe_t *, shell_t *);
char *get_execution_file_path(char *, shell_t *);
void simple_execution(shell_t *, instruction_t *);
void check_sig(shell_t *, int);
void bad_archi(shell_t *, char *);
char *get_redirect_filename(pipe_t *);
void redirect_stdin_double(pipe_t *);

/* --- builtins functions --- */
int exec_builtins(shell_t *, pipe_t *);
bool is_builtins(char *);
int cd_built(shell_t *, pipe_t *);
int env_built(shell_t *, pipe_t *);
int exit_built(shell_t *, pipe_t *);
int setenv_built(shell_t *, pipe_t *);
int unsetenv_built(shell_t *, pipe_t *);
void folder_error(shell_t *, int, char *);
unsigned int check_rollback_path(shell_t *, char *, unsigned int);
void go_home_cd(shell_t *);
void go_back_cd(shell_t *);
char *cd_special_cases(char *, char *, int *);
void save_old_pwd(char **);
void put_new_old_pwd(shell_t *, char *);
void restore_redirect(pipe_t *);
char **realloc_env(char **, int, int);
int destroy_cd_resources(char *);

#endif /* end of include guard: EXECUTION_H */

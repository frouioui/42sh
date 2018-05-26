/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the instruction structures and functions.
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

#define INSTRUCTION_SEPARATOR_ALL(s, i) (s[i] == ';' || (s[i] == '|' &&\
			s[i + 1] == '|') || (s[i] == '&' && s[i + 1] == '&'))
#define INSTRUCTION_SEPARATOR_ONE(s, i) (s[i] == ';' || s[i] == '|' ||\
			s[i] == '&')
#define INSTRUCTION_SEPARATOR  ';'
#define OR_INSTRUCTION_SEPARATOR  '|'
#define AND_INSTRUCTION_SEPARATOR  '&'
#define IS_AND_CONDITION(s, i) (s[i] == '&' && s[i + 1] == '&')
#define IS_OR_CONDITION(s, i) (s[i] == '|' && s[i + 1] == '|')
#define IS_NO_CONDITION(s, i) (s[i] == ';')
#define PIPE_SEPARATOR '|'
#define ENV_VARIABLE_CHAR '$'
#define REDIRECT_CHAR(c) (c == '>' || c == '<')
#define SPACE_TAB(c) (c == ' ' || c == '\t')
#define DIGIT(c) (c >= '0' && c <= '9')
#define ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define ALPHANUM(c) (DIGIT(c) || ALPHA(c))
#define HISTORY_FLAG(c) (c[0] == '!' && c[1] == '-' && c[2])
#define UNSET_PIPE (fd[instruction->actual_pipe][0] == -1 || \
fd[instruction->actual_pipe][1] == -1)

// Grammar
#define NB_PIPE (instruction->number_of_pipe - 1)

typedef enum type_redirect_s {
	EMPTY_REDIR,
	STDOUT_SIMPLE,
	STDOUT_DOUBLE,
	STDIN_SIMPLE,
	STDIN_DOUBLE,
	STDERR_SIMPLE,
	STDERR_DOUBLE
} redirect_t;

typedef enum error_syntax_s {
	EMPTY_ERR,
	INVALID_PIPE,
	INVALID_REDIRECT_NAME,
	AMBIGUOUS_REDIRECT
} error_syntax_t;

typedef enum condition_s {
	NO,
	AND,
	OR
} condition_t;

typedef enum execution_s {
	FORGROUND,
	BACKGROUND
} execution_t;

typedef struct pipe_s {
	char *full_instruction;
	char **args;
	char *path_exec;
	char *file_redirect;
	int fd;
	int pipe[2];
	bool valid;
	bool redirect;
	bool ampersand;
	error_syntax_t error;
	execution_t running;
	redirect_t type_redirect;
} pipe_t;

typedef struct instruction_s {
	char *full_instruction;
	unsigned char last_code;
	unsigned int number_of_pipe;
	unsigned int actual_pipe;
	bool valid;
	error_syntax_t error;
	pipe_t **pipe;
	condition_t condition;
} instruction_t;

typedef struct command_line_s {
	char *full_command;
	unsigned int number_instruction;
	instruction_t **instruction;
	bool valid;
} command_line_t;

/* --- basic instructions function (parsing) --- */
void free_command(command_line_t *);
void free_array_string(char **);
unsigned int get_number_instruction(char *);
command_line_t *get_command_line(bool, char *, char **);
unsigned int fill_up_instruction(bool, instruction_t **, char **);
unsigned int get_pipe_number(instruction_t *);
pipe_t **get_pipe(bool, instruction_t *, char **);
unsigned int get_redirect(bool , pipe_t **, unsigned int);
unsigned int analyse_redirect(bool , pipe_t *);
void check_env_variable(char **, char **);
void fix_extra_spaces(char *);
void display_error_instruction(instruction_t *);
bool is_empty_input(char *);
void check_quote(char **);
void get_condition(instruction_t *, char *);
instruction_t *new_instruction(char *);

/* --- functions for direct transformation (inside shell_loop) --- */
char *apply_transformation(bool, char *, char **);
char *get_history(char **, char **);
void get_ampersand(pipe_t *);

/* --- functions for the history --- */
unsigned int size_history(char **);
char **get_whole_history(char **);

#endif /* end of include guard: INSTRUCTION_H */

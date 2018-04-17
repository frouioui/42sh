##
## EPITECH PROJECT, 2018
## PSU_2017_42sh
## File description:
## Makefile of the 42sh project
##

## ---- NAMES ---- ##

BINARY_NAME	=	42sh

DEBUG_BINARY_NAME	=	42sh_debug

TEST_BINARY_NAME	=	42sh_test

## ---- FUNCTIONS ---- ##

CC	=	gcc $(HEADER) $(CDFLAG)

## ---- PATHS ---- ##

PATH_SRC	=	./src

PATH_TEST	=	./tests

## ---- SOURCE FILES ---- ##

SRCS	=	$(PATH_SRC)/check_args.c \
		$(PATH_SRC)/destroy_shell.c \
		$(PATH_SRC)/initialisation_shell/copy_environement.c \
		$(PATH_SRC)/initialisation_shell/initialisation_shell.c \
		$(PATH_SRC)/initialisation_shell/set_env_echec_mode.c \
		$(PATH_SRC)/initialisation_shell/initialisation_backup.c \
		$(PATH_SRC)/initialisation_shell/is_bonus_shell.c \
		$(PATH_SRC)/shell_loop/transformation/apply_transformation.c \
		$(PATH_SRC)/shell_loop/parsing/get_command_line.c \
		$(PATH_SRC)/shell_loop/parsing/get_number_instruction.c \
		$(PATH_SRC)/shell_loop/shell_loop.c \
		$(PATH_SRC)/shell_loop/write_command_history.c \
		$(PATH_SRC)/shell_loop/free_command.c \
		$(PATH_SRC)/shell_loop/update_backup.c \
		$(PATH_SRC)/shell_loop/free_array_string.c \
		$(PATH_SRC)/shell_loop/prompt/display_bonus_prompt.c \
		$(PATH_SRC)/shell_loop/prompt/display_prompt.c \
		$(PATH_SRC)/shell_loop/parsing/get_pipe_number.c \
		$(PATH_SRC)/shell_loop/parsing/fill_up_instruction.c \
		$(PATH_SRC)/shell_loop/parsing/get_pipe.c \
		$(PATH_SRC)/shell_loop/parsing/get_redirect.c \
		$(PATH_SRC)/shell_loop/parsing/check_env_variable.c \
		$(PATH_SRC)/shell_loop/parsing/fix_extra_space.c \
		$(PATH_SRC)/shell_loop/parsing/check_quote.c \
		$(PATH_SRC)/shell_loop/execution/builtins/cd_built.c \
		$(PATH_SRC)/shell_loop/execution/builtins/env_built.c \
		$(PATH_SRC)/shell_loop/execution/builtins/setenv_built.c \
		$(PATH_SRC)/shell_loop/execution/builtins/unsetenv_built.c \
		$(PATH_SRC)/shell_loop/execution/builtins/exit_built.c \
		$(PATH_SRC)/shell_loop/execution/builtins/exec_builtins.c \
		$(PATH_SRC)/shell_loop/execution/builtins/is_builtins.c \
		$(PATH_SRC)/shell_loop/execution/builtins/cd_special_cases.c \
		$(PATH_SRC)/shell_loop/execution/builtins/put_new_old_pwd.c \
		$(PATH_SRC)/shell_loop/execution/builtins/error_wrong_folder.c \
		$(PATH_SRC)/shell_loop/execution/builtins/save_old_pwd.c \
		$(PATH_SRC)/shell_loop/execution/builtins/realloc_env.c \
		$(PATH_SRC)/shell_loop/execution/builtins/destroy_cd_resources.c \
		$(PATH_SRC)/shell_loop/execution/get_redirected.c \
		$(PATH_SRC)/shell_loop/execution/multiple_execution.c \
		$(PATH_SRC)/shell_loop/execution/execute_command.c \
		$(PATH_SRC)/shell_loop/execution/create_pipe.c \
		$(PATH_SRC)/shell_loop/execution/exec_pipe.c \
		$(PATH_SRC)/shell_loop/execution/redirect_pipe.c \
		$(PATH_SRC)/shell_loop/execution/error_exec.c \
		$(PATH_SRC)/shell_loop/execution/dup_my_pipe.c \
		$(PATH_SRC)/shell_loop/execution/get_path_exec.c \
		$(PATH_SRC)/shell_loop/execution/get_execution_file_path.c \
		$(PATH_SRC)/shell_loop/execution/simple_execution.c \
		$(PATH_SRC)/shell_loop/execution/check_sig.c \
		$(PATH_SRC)/shell_loop/execution/display_error_instruction.c \
		$(PATH_SRC)/shell_loop/execution/redirect_stdin_double.c \

SRC_MAIN	=	$(PATH_SRC)/main.c

SRCS_TEST	=

## ---- FLAGS ---- ##

LIB	=	-L./lib/ -lmy

TEST_FLAGS	=	-lcriterion --coverage

DEBUG_FLAG	=	-g3

HEADER	=	-I./include/

CDFLAG	=	-W -Wextra

## ---- OBJS ---- ##

OBJS	=	$(SRCS:.c=.o) $(SRC_MAIN:.c=.o)

## ---- RULES ---- ##

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	make -C./lib/
	$(CC) -o $(BINARY_NAME) $(HEADER) $(OBJS) $(LIB)

tests_run:
	make -C./lib/
	$(CC) $(SRCS) -o $(TEST_BINARY_NAME) $(HEADER) $(TEST_FLAG) $(LIB)
	./$(BINARY_NAME) --always-succeed

debug:
	make -C./lib/
	$(CC) $(SRCS) $(SRC_MAIN) -o $(DEBUG_BINARY_NAME) $(HEADER) $(LIB) $(DEBUG_FLAG)
	./$(DEBUG_BINARY_NAME)

clean:
	make clean -C./lib/
	rm -f $(OBJS) *.gc*

fclean: clean
	make fclean -C./lib/
	rm -f $(BINARY_NAME) $(DEBUG_BINARY_NAME) $(TEST_BINARY_NAME)

re: fclean all

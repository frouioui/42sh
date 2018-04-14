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

COMPILE	=	gcc

## ---- PATHS ---- ##

PATH_SRC	=	./src

PATH_TEST	=	./tests

## ---- SOURCE FILES ---- ##

SRCS	=

SRC_MAIN	=	$(PATH_SRC)/main.c

SRCS_TEST	=

## ---- FLAGS ---- ##

LIB	=	-L./lib/ -lmy

TEST_FLAGS	=	-lcriterion --coverage

DEBUG_FLAG	=	-g3

HEADER	=	-I./include/

CDFLAG	=	-W -Wall -Wextra -Werror -pedantic

## ---- OBJS ---- ##

OBJS	=	$(SRCS:.c=.o) \
		$(SRC_MAIN:.c=.o)

## ---- RULES ---- ##

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	make -C./lib/
	$(COMPILE) $(OBJS) -o $(BINARY_NAME) $(HEADER) $(LIB)

tests_run:
	make -C./lib/
	$(COMPILE) $(SRCS) -o $(TEST_BINARY_NAME) $(HEADER) $(TEST_FLAG) $(LIB)
	./$(BINARY_NAME) --always-succeed

debug:
	make -C./lib/
	$(COMPILE) $(SRCS) $(SRC_MAIN) -o $(DEBUG_BINARY_NAME) $(HEADER) $(LIB) $(DEBUG_FLAG)
	./$(DEBUG_BINARY_NAME)

clean:
	make clean -C./lib/
	rm -f $(OBJS) *.gc*

fclean: clean
	make fclean -C./lib/
	rm -f $(BINARY_NAME) $(DEBUG_BINARY_NAME) $(TEST_BINARY_NAME)

re: fclean all

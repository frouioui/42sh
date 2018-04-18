## EPITECH PROJECT, 2017
## Makefile
## File description:
## julien.ollivier@epitech.eu
##

SRC	=	./my/get_next_line.c \
		./my/my_atoi.c \
		./my/my_get_env.c \
		./my/my_get_line_env.c \
		./my/my_getenv_root.c \
		./my/my_number_row.c \
		./my/my_putchar.c \
		./my/my_putstr.c \
		./my/my_str_to_words_array.c \
		./my/my_strcmp.c \
		./my/my_strcpy.c \
		./my/my_strlen.c \
		./my/my_ischar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./libmy.a

CC	=	gcc $(HEADER)

HEADER	=	-I../include/

CDFLAG	=	-W -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ar t $(NAME)

clean:
	rm -f $(OBJ)
	find -type f -name "*~" -delete -o -type f -name "#*#" -delete

fclean: clean
	rm -f $(NAME) a.out

re:	fclean all

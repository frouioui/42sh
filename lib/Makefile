## EPITECH PROJECT, 2017
## Makefile
## File description:
## julien.ollivier@epitech.eu
##

SRC	=

OBJ	=	$(SRC:.c=.o)

NAME	=	./libmy.a

CC	=	gcc $(HEADER)

HEADER	=	-I../include/

CDFLAG	=	-W -Wall -Wextra -pedantic -O3

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

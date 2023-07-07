##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCPASS =	./lib/my/

SRC	=	my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_putnbr_base.c		\
		my_printf.c			\
		my_getstr.c			\

OBJ	=	$(patsubst %.c, $(SRCPASS)%.o, $(SRC))

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o test tests/test.c libmy.a --coverage -lcriterion

run_tests:
	./test

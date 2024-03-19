##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	 =	./src/lst/add.c						\
		./src/lst/create.c					\
		./src/lst/disp.c					\
		./src/lst/free_lst.c				\
		./src/lst/link.c					\
		./src/put/mini_printf.c				\
		./src/put/my_put_nbr.c				\
		./src/put/my_putchar.c				\
		./src/put/my_putstr.c				\
		./src/main.c						\

TESTSRC	=	./src/put/my_putstr.c			\
			./tests/put/test_my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS  =       -Wall -Wextra -I ./include/ -g3

HEADER	=	my.h

NAME	=	amazed

TEST	=	uni_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f *~
	rm -f *.gc*
	rm -f *vgcore*
	rm -f *.log
	rm -f *.gcno
	rm -f *.gcda

re:	fclean all

$(TEST):	fclean
	$(CC) -o $(TEST) $(TESTSRC) --coverage -lcriterion $(CFLAGS)

tests_run:	$(TEST)
	./$(TEST)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	all $(NAME) clean fclean re $(TEST) tests_run

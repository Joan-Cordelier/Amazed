##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	 =	./src/graph/add.c					\
		./src/graph/create.c				\
		./src/graph/disp.c					\
		./src/graph/free_lst.c				\
		./src/graph/link.c					\
		./src/lst/add.c						\
		./src/lst/del.c						\
		./src/lst/disp.c					\
		./src/lst/free_lst.c				\
		./src/put/mini_printf.c				\
		./src/put/my_put_nbr.c				\
		./src/put/my_putchar.c				\
		./src/put/my_putstr.c				\
		./src/put/my_show_word_array.c		\
		./src/str/is_in_str.c				\
		./src/str/my_str_to_word_array.c	\
		./src/str/my_strcmp.c				\
		./src/str/my_strcpy.c				\
		./src/str/my_strdup.c				\
		./src/str/my_strlen.c				\
		./src/str/my_strsub.c				\
		./src/str/remoove_tag_str.c			\
		./src/free.c						\
		./src/main.c						\
		./src/struct_utils.c				\

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

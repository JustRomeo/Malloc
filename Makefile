##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRCS = src/
LIBS = $(SRCS)lib/
MEMS = $(SRCS)memory_gestion/

SRC =	$(SRCS)malloc.c		\
		$(SRCS)free.c		\
		$(SRCS)realloc.c	\
		$(SRCS)calloc.c 	\
							\
		$(MEMS)memory.c		\
		$(MEMS)dataBlock.c	\
							\
		$(LIBS)my_put_nbr.c	\
		$(LIBS)my_putstr.c	\

SRCT =	tests/test.cpp	\

OBJ =	$(SRC:.c=.o)

CC = gcc

CRIT =	--coverage -lcriterion

WALL =	-Wall -Wextra

NAME =	libmy_malloc.so
CRITERION = unit_tests

CFLAGS = -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -c $(WALL) -fpic $(SRC) $(CFLAGS)
			$(CC) -shared -o $(NAME) *.o -I./include
			rm -f $(OBJ)

tests_run:	$(OBJ)
			$(CC) -o $(CRITERION) $(CRIT) $(OBJ) $(CFLAGS)
			./$(CRITERION)

clean_test: $(OBJ)
			$(CC) -o $(CRITERION) $(CRIT) $(OBJ)
			./$(CRITERION)
			gcovr
			rm -f *.o
			rm -f *.gcno
			rm -f *.gcda
			rm -f $(CRITERION)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(CRITERION)

fclean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(CRITERION)
	rm -f $(NAME)

re:	fclean all
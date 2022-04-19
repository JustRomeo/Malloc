##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

EXREF = ex00/

SRC =	tests/test.cpp			\
		$(EXREF)Errors.cpp		\

OBJ =	$(SRC:.c=.o)

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CRITERION = unit_tests

tests_run:	$(OBJ)
			g++ -o $(CRITERION) $(CRIT) $(OBJ) $(INCLUDE)
			./$(CRITERION)

clean_test: $(OBJ)
			g++ -o $(CRITERION) $(CRIT) $(OBJ)
			./$(CRITERION)
			gcovr
			rm -vf *.o
			rm -vf *.gcno
			rm -vf *.gcda
			rm $(CRITERION)

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean tests_run

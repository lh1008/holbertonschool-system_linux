CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3

SRC0 = 4-request.c server.c util.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0

SRC1 = 5-queries.c server.c util.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = todo_api_1

SRC2 = 6-headers.c server.c util.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = todo_api_2

SRC3 = 7-body.c server.c util.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = todo_api_3

SRC5 = 9-get_all_todos.c server.c util.c
OBJ5 = $(SRC5:.c=.o)
NAME5 = todo_api_5

.PHONY: all clean oclean flcean re

all: $(OBJ0) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ5)
	$(CC) $(OBJ0) -o $(NAME0)
	$(CC) $(OBJ1) -o $(NAME1)
	$(CC) $(OBJ2) -o $(NAME2)
	$(CC) $(OBJ3) -o $(NAME3)
	$(CC) $(OBJ5) -o $(NAME5)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)
	$(RM) *~ $(NAME2)
	$(RM) *~ $(NAME3)
	$(RM) *~ $(NAME5)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ5)

fclean: clean oclean

re: oclean all

todo_api_0: http.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

todo_api_1: http.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

todo_api_2: http.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

todo_api_3: http.h $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)

todo_api_5: http.h $(OBJ5)
	$(CC) $(OBJ5) -o $(NAME5)

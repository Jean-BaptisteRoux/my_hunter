##
## EPITECH PROJECT, 2023
## ProjectDay03
## File description:
## test
## test
##

CC = gcc
CFLAGS = -Wall -Wextra
FLAGS = -lm -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
EXEC = my_hunter
SRC_FILES = $(wildcard code_source/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	@($(CC) -o $(EXEC) $^ $(FLAGS))
	@(echo "Éxecutable compilé")

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))
	@(echo "Fichiers .o compilés")

lib:$(OBJ_FILES)
	@(ar rc libmy.a $^)

.PHONY: clean fclean

clean:
	@(rm -f libmy.a)
	@(rm -f *.o $(OBJ_FILES))
	@(echo "Fichiers .o supprimés")

fclean: clean
	@(rm -f $(EXEC))
	@(echo "Éxecutable supprimé")

run:$(EXEC)
	@(./$(EXEC))

code: fclean
	@(~/coding-style-checker/coding-style.sh . .)
	@(cat coding-style-reports.log)

re :	fclean all

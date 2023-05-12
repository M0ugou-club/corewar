##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC = 

OBJ = $(SRC:.c=.o)

NAME = corewar

CFLAGS = 

LDFLAGS =

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re : fclean all

.PHONY: all clean fclean re

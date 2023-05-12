##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC = ./src/get_prog_list.c \
	  ./src/open_file.c \
	  ./src/test.c

OBJ = $(SRC:.c=.o)

NAME = asm

CFLAGS = -W -Wall -Wextra -I./include

LDFLAGS = -L ../lib -lmy

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re : fclean all

.PHONY : all clean fclean re
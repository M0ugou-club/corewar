##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC =	src/memory/create_mem.c \
		src/memory/list_process.c \
		src/memory/op.c \
		src/process_loop.c \
		src/vm.c \
		src/main.c

OBJ = $(SRC:.c=.o)

NAME = corewar

CFLAGS = -W -Wall -Wextra -Iinclude

LDFLAGS = -L../lib/lmy

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

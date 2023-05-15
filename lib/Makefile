##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC = ./src/my_memset.c \
	  ./src/my_strdup.c \
	  ./src/my_strlen.c \
	  ./src/my_strclear.c \
	  ./src/my_atoi.c \
	  ./src/my_strcmp.c \
	  ./src/my_power.c \
	  ./src/str_is_num.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -W -Wall -Wextra -I./include

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re : fclean all

.PHONY : all clean fclean re

##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC = my_memset.c \
	  my_strdup.c \
	  my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = my.a

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

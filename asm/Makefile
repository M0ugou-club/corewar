##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC = ./src/get_prog_list.c \
	  ./src/open_file.c \
	  ./src/get_format_value.c \
	  ./src/get_number_value.c \
	  ./src/fill_line.c \
	  ./src/load_tab.c \
	  ./src/change_label_value.c \
	  ./src/get_line_array.c \
	  ./src/is_label.c \
	  ./src/change_size_index.c \
	  ./src/write_file.c \
	  ./src/get_all_label.c \
	  ./src/asm.c \
	  ./src/main.c \
	  ./src/compil_line.c \
	  ./src/compil/calculation.c \
	  ./src/compil/compil_aff.c \
	  ./src/compil/compil_one_format.c \
	  ./src/compil/load.c \
	  ./src/compil/operator.c \
	  ./src/compil/store.c

OBJ = $(SRC:.c=.o)

NAME = asm

CFLAGS = -W -Wall -Wextra -I./include -g3

LDFLAGS = -L ../lib -lmy -g3

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
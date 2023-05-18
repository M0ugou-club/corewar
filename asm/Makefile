##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

UTILS =  ./src/utils/get_line_array.c \
		 ./src/utils/open_file.c \
		 ./src/utils/manip_index.c \
		 ./src/utils/create_new_file.c \
		 ./src/utils/get_str.c \
		 ./src/compil/utils/load_tab.c \
		 ./src/compil/utils/change_size_index.c \
		 ./src/compil/utils/fill_line.c \
		 ./src/compil/utils/get_format_value.c \
		 ./src/compil/utils/get_number_value.c

COMPIL = ./src/compil/compiler.c \
		 ./src/compil/error_handling.c

LABEL = ./src/label/change_label_value.c \
		./src/label/get_all_label.c \
		./src/label/is_label.c

HEADER = ./src/header/compil_header.c \
		 ./src/header/print_error.c

MAIN = ./src/get_prog_list.c \
	   ./src/write_file.c \
	   ./src/compil_line.c \
	   ./src/op.c \
	   ./src/asm.c \
	   ./src/main.c

SRC = $(UTILS) $(COMPIL) $(LABEL) $(HEADER) $(MAIN)

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

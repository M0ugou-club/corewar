##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

UTILS =  ./src/utils/get_line_array.c \
		 ./src/utils/load_tab.c \
		 ./src/utils/open_file.c \
		 ./src/utils/manip_index.c \
		 ./src/compil/utils/change_size_index.c \
		 ./src/compil/utils/fill_line.c \
		 ./src/compil/utils/get_format_value.c \
		 ./src/compil/utils/get_number_value.c

COMPIL = ./src/compil/calculation.c \
		 ./src/compil/compil_aff.c \
		 ./src/compil/compil_one_format.c \
		 ./src/compil/load.c \
		 ./src/compil/operator.c \
		 ./src/compil/store.c

LABEL = ./src/label/change_label_value.c \
		./src/label/get_all_label.c \
		./src/label/is_label.c

MAIN = ./src/get_prog_list.c \
	   ./src/write_file.c \
	   ./src/asm.c \
	   ./src/main.c \
	   ./src/compil_line.c \

SRC = $(UTILS) $(COMPIL) $(LABEL) $(MAIN)

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

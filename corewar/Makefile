##
## EPITECH PROJECT, 2023
## structure
## File description:
## Makefile
##

SRC =   src/champion/put_champion.c\
		src/memory/create_mem.c \
		src/memory/list_process.c \
		src/memory/op.c \
		src/vm.c \
		src/main.c \
		src/param_parser.c \
		src/get_nb_champ.c \
		src/champion/handle_champ.c \
		src/get_champ_info.c \
		src/check_opt.c \
		src/write_final_state.c \

OBJ = $(SRC:.c=.o)

NAME = corewar

CFLAGS = -W -Wall -Wextra -Iinclude

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

.PHONY: all clean fclean re

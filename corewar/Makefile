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
		src/process_loop.c \
		src/function/utils/utils/get_coding_byte.c \
		src/function/utils/utils/get_error.c \
		src/function/utils/utils/get_value.c \
		src/function/utils/utils/increase_index.c \
		src/function/utils/utils/write_memory.c \
		src/function/addition.c \
		src/function/aff.c \
		src/function/fork.c \
		src/function/ld.c \
		src/function/ldi.c \
		src/function/live.c \
		src/function/lld.c \
		src/function/lldi.c \
		src/function/logic_operator.c \
		src/function/st.c \
		src/function/sti.c \
		src/function/xor.c \
		src/function/zjmp.c

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

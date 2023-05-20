##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

all : 
	make -C lib/
	make -C asm/
	make -C corewar/

clean :
	make clean -C asm
	make clean -C corewar
	make clean -C lib

fclean : clean
	make fclean -C asm
	make fclean -C corewar
	make fclean -C lib

re : fclean all

.PHONY : asm corewar all clean fclean re

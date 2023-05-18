##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

asm :
	make -C lib/
	make -C asm/

corewar :
	make -C lib/
	make -C corewar/

all : $(asm) $(corewar)

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

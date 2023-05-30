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
	make clean -C bonus

fclean : clean
	make fclean -C asm
	make fclean -C corewar
	make fclean -C lib
	make fclean -C bonus

re : fclean all

bonus: fclean
	make -C lib
	make -C corewar bonus -s
	make -C bonus -s

.PHONY : asm corewar all clean fclean re

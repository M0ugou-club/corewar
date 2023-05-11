##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

asm :
	make -C asm/

corewar :
	make -C corewar/

all : $(asm) $(corewar)

clean :

fclean : clean

re : fclean all

.PHONY : $(asm) $(corewar) 
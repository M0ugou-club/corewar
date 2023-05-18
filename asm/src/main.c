/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        if (process_asm(av[i]) == -1) {
            return (84);
        }
    }
    return (0);
}

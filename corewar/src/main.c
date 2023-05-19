/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** main.c
*/

#include <stdlib.h>

static int error_handling(int ac, char **argv)
{
    return 0;
}

int main(int ac, char **argv)
{
    if (error_handling(ac, argv) != 0) {
        return 84;
    }
    return 0;
}
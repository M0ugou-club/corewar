/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_memset
*/

#include <stddef.h>

int my_memset(char *str, char byte, int len)
{
    int i = 0;

    if (str == NULL) {
        return (-1);
    }
    while (i < len) {
        str[i] = byte;
        i++;
    }
    return (0);
}

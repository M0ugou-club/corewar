/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_memset
*/

#include <stddef.h>

int my_int_memset(int *tab, int byte, int len)
{
    int i = 0;

    if (tab == NULL) {
        return (-1);
    }
    while (i < len) {
        tab[i] = byte;
        i++;
    }
    return (0);
}

int my_tab_memset(char **data, char *byte, int len)
{
    int i = 0;

    if (data == NULL) {
        return (-1);
    }
    while (i < len) {
        data[i] = byte;
        i++;
    }
    return (0);
}

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

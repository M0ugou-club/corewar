/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL) {
        return (len);
    }
    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int my_tablen(char **tab)
{
    int len = 0;

    if (tab == NULL) {
        return (len);
    }
    while (tab[len] != NULL) {
        len++;
    }
    return (len);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strcpy
*/

#include <stddef.h>

int my_strncpy(char *dest, char const *src, int len)
{
    if (dest == NULL || src == NULL) {
        return (-1);
    }
    for (int i = 0; src[i] != '\0' && i < len; i++) {
        dest[i] = src[i];
    }
    return (0);
}

int my_strcpy(char *dest, char const *src)
{
    if (dest == NULL || src == NULL) {
        return (-1);
    }
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (0);
}

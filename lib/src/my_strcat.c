/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strcat
*/

#include <stddef.h>

int my_strncat(char *dest, char const *src, int len)
{
    int index = 0;

    if (src == NULL || dest == NULL) {
        return (-1);
    }
    while (src[index] != '\0') {
        index++;
    }
    for (int i = 0; dest[i] != '\0' && i < len; i++) {
        dest[index + i] = src[i];
    }
    return (0);
}

int my_strcat(char *dest, char const *src)
{
    int index = 0;

    if (src == NULL || dest == NULL) {
        return (-1);
    }
    while (src[index] != '\0') {
        index++;
    }
    for (int i = 0; src[i] != '\0'; i++) {
        dest[index + i] = src[i];
    }
    return (0);
}

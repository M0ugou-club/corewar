/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strcmp
*/

#include <stddef.h>
#include "my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL) {
        return (-1);
    }
    while (str1[i] != '\0' && str2[i] != '\0' && i < n) {
        if (str1[i] != str2[i]) {
            return (1);
        }
        i++;
    }
    return (0);
}

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL) {
        return (-1);
    }
    if (my_strlen(str1) != my_strlen(str2)) {
        return (1);
    }
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (1);
        }
        i++;
    }
    return (0);
}

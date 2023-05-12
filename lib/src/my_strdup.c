/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    char *new_str = NULL;
    int len = 0;
    int i = 0;

    if (str == NULL) {
        return (NULL);
    }
    len = my_strlen(str);
    new_str = malloc(sizeof(char) * (len + 1));
    my_memset(new_str, '\0', len + 1);
    while (i < len) {
        new_str[i] = str[i];
        i++;
    }
    return (new_str);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strclear
*/

#include <stdlib.h>
#include "my.h"

static char *remove_tab(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t' || str[i] == ',') {
            str[i] = ' ';
        }
        i++;
    }
    return (str);
}

static int get_start_buff(char *str)
{
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }
    return (i);
}

static char *clear_str(char const *copy, char *new_str, int start)
{
    int index = 0;
    int i = start;

    while (copy[i] != '\0') {
        if ((copy[i] != ' ') || (copy[i + 1] != ' ' && copy[i + 1] != '\0')) {
            new_str[index] = copy[i];
            index++;
        }
        i++;
    }
    return (new_str);
}

char *my_strclear(char const *str)
{
    char *copy = NULL;
    char *new_str = NULL;
    int start = 0;

    copy = my_strdup(str);
    if (copy == NULL) {
        return (NULL);
    }
    copy = remove_tab(copy);
    start = get_start_buff(copy);
    new_str = malloc(sizeof(char) * (my_strlen(copy) - start + 1));
    if (new_str == NULL) {
        return (NULL);
    }
    my_memset(new_str, '\0', my_strlen(copy) - start + 1);
    new_str = clear_str(copy, new_str, start);
    free(copy);
    return (new_str);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** is_label
*/

#include "asm.h"
#include "op.h"
#include "my.h"

int compare_char(char compare)
{
    int error = -1;
    int i = 0;

    while (LABEL_CHARS[i] != '\0') {
        if (compare == LABEL_CHARS[i]) {
            error = 0;
        }
        i++;
    }
    return (error);
}

int is_label(char const *arg)
{
    int len = 0;
    int error = 0;

    if (my_strncmp(arg, "%:", my_strlen("%:")) != 0
        && my_strncmp(arg, ":", my_strlen(":")) != 0) {
        return (-1);
    }
    while (arg[len] != LABEL_CHAR) {
        len++;
    }
    len++;
    while (arg[len] != '\0') {
        error += compare_char(arg[len]);
        len++;
    }
    return (error);
}

int is_only_label_line(char const *arg)
{
    int len = 0;

    len = my_strlen(arg);
    if (arg[len - 1] == ':') {
        return (0);
    }
    return (-1);
}

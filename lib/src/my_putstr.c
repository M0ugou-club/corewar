/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_putstr
*/

#include <unistd.h>
#include <stddef.h>
#include "my.h"

int my_putstr(char const *str, int output)
{
    if (str == NULL) {
        return (-1);
    }
    write(output, str, my_strlen(str));
    return (0);
}

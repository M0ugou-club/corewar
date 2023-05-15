/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** str_is_num
*/

#include <stddef.h>

int my_str_is_num(char const *str)
{
    int i = 0;
    
    if (str == NULL) {
        return (-1);
    }
    if (str[i] == '-') {
        i++;
    }
    while(str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return (-1);
        }
    }
    return (0);
}

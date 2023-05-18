/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_format_value
*/

#include <stddef.h>
#include "asm.h"
#include "my.h"

static const format_t format_value[] = {{"r", 0, 1},
{"%", 1, 0},
{NULL, 1, 1}};

static int increase_value(int bit_strenght, char const *arg)
{
    int value = 0;
    int i = 0;

    while (format_value[i].type != NULL) {
        if (my_strncmp(arg, format_value[i].type,
            my_strlen(format_value[i].type)) == 0) {
            value += my_power(2 * format_value[i].bit1, bit_strenght);
            value += my_power(2 * format_value[i].bit2, bit_strenght - 1);
        }
        i++;
    }
    if (value == 0) {
        value += my_power(2 * format_value[i].bit1, bit_strenght);
        value += my_power(2 * format_value[i].bit2, bit_strenght - 1);
    }
    return (value);
}

int get_format_value(char **args)
{
    int i = 0;
    int bit_strenght = 7;
    int value = 0;

    while (args[i] != NULL) {
        value += increase_value(bit_strenght, args[i]);
        bit_strenght -= 2;
        i++;
    }
    return (value);
}

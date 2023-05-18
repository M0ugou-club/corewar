/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** change_size_index
*/

#include "op.h"
#include "asm.h"

static int change_char_tab(char *num, int size)
{
    char tmp = 0;
    int i = 0;

    while (i < size / 2) {
        tmp = num[size - i - 1];
        num[size - i - 1] = num[i];
        num[i] = tmp;
        i++;
    }
    return (0);
}

int change_size_index(command_int_t *command_int)
{
    for (int i = 0; command_int->value_size[i] != -1; i++) {
        if (command_int->value_size[i] == DIR_SIZE) {
            change_char_tab(command_int->value[i], command_int->value_size[i]);
            command_int->value_size[i] = IND_SIZE;
            change_char_tab(command_int->value[i], command_int->value_size[i]);
        }
    }
    return (0);
}

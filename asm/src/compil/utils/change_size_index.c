/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** change_size_index
*/

#include "asm.h"

int change_size_index(command_int_t *command_int)
{
    for (int i = 0; command_int->value_size[i] != -1; i++) {
        if (command_int->value_size[i] == DIR_SIZE) {
            command_int->value_size[i] = IND_SIZE;
        }
    }
    return (0);
}

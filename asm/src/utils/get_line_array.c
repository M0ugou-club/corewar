/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_line_array
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int increase_index(command_int_t *command_int)
{
    int index = 0;

    if (command_int == NULL || command_int->value_size == NULL
        || command_int->value == NULL) {
        return (index);
    }
    for (int i = 0; command_int->value_size[i] != -1 && i < MAX_LENGTH; i++) {
        index += command_int->value_size[i];
    }
    return (index);
}

int get_line_array(prog_list_t *prog_list)
{
    prog_list_t *tmp = prog_list;

    while (tmp != NULL) {
        tmp->line_array = str_to_array(tmp->line, ' ');
        if (tmp->line_array == NULL) {
            return (-1);
        }
        tmp = tmp->next;
    }
    return (0);
}

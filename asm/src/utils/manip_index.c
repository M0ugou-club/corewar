/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** manip_index
*/

#include <stddef.h>
#include "asm.h"

int get_curr_index(prog_list_t *prog_list, prog_list_t *line)
{
    prog_list_t *tmp = prog_list;
    int index = 0;

    while (tmp != NULL && tmp != line) {
        index += increase_index(tmp->command_int);
        tmp = tmp->next;
    }
    return (index);
}

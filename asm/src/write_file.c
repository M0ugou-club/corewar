/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write_file
*/

#include "asm.h"

int write_file(prog_list_t *prog_list)
{
    int num = 0;
    prog_list_t *tmp = prog_list;

    while (tmp != NULL) {
        for (int i = 0; prog_list->command_int->value_size[i] != -1; i++) {
            num = prog_list->command_int->value[i];
            num = SWAP_ENDIAN(num);
            write(1, &num, prog_list->command_int->value_size[i]);
        }
        tmp = tmp->next;
    }
    return (0);
}

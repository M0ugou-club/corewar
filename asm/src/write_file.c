/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write_file
*/

#include <unistd.h>
#include "asm.h"

int write_int(char *num, int num_size)
{
    char nb = 0;

    for (int i = 0; i < num_size; i++) {
        nb = num[i];
        write(1, &nb, 1);
    }
    return (0);
}

int write_int_tab(command_int_t *command_int, prog_list_t *test)
{
    char *num = NULL;

    if (command_int->value == NULL || command_int->value_size == NULL) {
        return (0);
    }
    for (int i = 0; command_int->value_size[i] != -1; i++) {
        num = command_int->value[i];
        write_int(num, command_int->value_size[i]);
    }
    return (0);
}

int write_file(prog_list_t *prog_list)
{
    prog_list_t *tmp = prog_list;

    while (tmp != NULL) {
        if (tmp->command_int != NULL) {
            write_int_tab(tmp->command_int, tmp);
        }
        tmp = tmp->next;
    }
    return (0);
}

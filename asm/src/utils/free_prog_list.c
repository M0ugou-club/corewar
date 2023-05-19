/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free_prog_list
*/

#include <stdlib.h>
#include "asm.h"

static void free_command_int(command_int_t *command_int)
{
    if (command_int != NULL) {
        if (command_int->value != NULL) {
            free_tab(command_int->value);
        }
        if (command_int->value_size != NULL) {
            free(command_int->value_size);
        }
        free(command_int);
    }
}

void free_tab(char **tab)
{
    if (tab != NULL) {
        for (int i = 0; tab[i] != NULL; i++) {
            free(tab[i]);
        }
        free(tab);
    }
}

void free_prog_list(prog_list_t *prog_list)
{
    if (prog_list == NULL) {
        return;
    }
    if (prog_list->next != NULL) {
        free_prog_list(prog_list->next);
    }
    free_command_int(prog_list->command_int);
    free_tab(prog_list->line_array);
    if (prog_list->line != NULL) {
        free(prog_list->line);
    }
    if (prog_list->label != NULL) {
        free(prog_list->label);
    }
    free(prog_list);
}

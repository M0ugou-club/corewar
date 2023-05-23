/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "process.h"
#include "vm.h"

int count_champ(process_t *list_champ)
{
    int nb_champ = 0;
    process_t *current = list_champ;

    while (current) {
        nb_champ += 1;
        current = current->next;
    }
    return nb_champ;
}

void free_champ(process_t *list_champ)
{
    process_t *current = list_champ;
    process_t *next = NULL;

    while (current) {
        next = current->next;
        if (current->id != NULL) {
            free(current->id);
        }
        if (current->registers != NULL) {
            free(current->registers);
        }
        free(current);
        current = next;
    }
}

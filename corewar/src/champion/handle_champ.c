/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include <stdlib.h>
#include <string.h>
#include "process.h"

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

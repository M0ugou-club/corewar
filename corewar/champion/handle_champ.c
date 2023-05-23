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

int verify_size_champ(process_t *list_champ, int section_size)
{
    process_t *current = list_champ;
    int size_of_code = 0;

    while (current) {
        size_of_code = strlen(current->code);
        if (size_of_code > section_size) {
            return -1;
        }
        current = current->next;
    }
    return 0;
}

void free_champ(process_t *list_champ)
{
    process_t *current = list_champ;
    process_t *next = NULL;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

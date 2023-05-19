/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include "../op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "my.h"

typedef struct process {
    char *id;
    char *code;
    int index;
    struct process *next;
} process_t;

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

void print_champ(process_t *liste)
{
    process_t *current = liste;
    while (current != NULL) {
        printf("ID: %s\n", current->id);
        printf("Code: %s\n", current->code);
        printf("\n");
        current = current->next;
    }
}

void free_champ(process_t *list_champ)
{
    process_t *current = list_champ;
    process_t *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

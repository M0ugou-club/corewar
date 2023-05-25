/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** list_process
*/

#include <stdlib.h>
#include "process.h"

void destroy_process_list(process_t *list)
{
    process_t *tmp = NULL;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->id);
        free(tmp->registers);
        free(tmp);
    }
}

process_t *add_process(process_t *to_add, process_t *list)
{
    process_t *tmp = NULL;

    if (to_add == NULL) {
        return NULL;
    }
    if (list == NULL) {
        return (to_add);
    }
    tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = to_add;
    return list;
}

int copy_registers(int *new_reg, int *to_copy)
{
    for (int i = 0; i != REG_NUMBER; i++) {
        new_reg[i] = to_copy[i];
    }
    return (new_reg);
}

process_t *copy_process(int index, char *id, process_t *to_copy)
{
    process_t *new = NULL;

    new = malloc(sizeof(process_t));
    if (new == NULL) {
        return (NULL);
    }
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    if (new->registers == NULL) {
        return NULL;
    }
    copy_registers(new->registers, to_copy->registers);
    new->id = id;
    new->nb_champ = to_copy->nb_champ;
    new->cooldown = 0;
    new->index = index;
    new->next = NULL;
    new->last_lives = 0;
    new->cooldown = 0;
    return (new);
}

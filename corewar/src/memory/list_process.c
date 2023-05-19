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

    if (to_add == NULL || list == NULL) {
        return NULL;
    }
    tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = to_add;
    return list;
}

process_t *create_process(int index, char *id)
{
    process_t *list = NULL;

    list = malloc(sizeof(process_t));
    if (list == NULL) {
        return (NULL);
    }
    list->registers = malloc(sizeof(int) * REG_NUMBER);
    if (list->registers == NULL) {
        return NULL;
    }
    list->id = id;
    list->index = index;
    list->next = NULL;
    list->last_lives = 0;
    return (list);
}

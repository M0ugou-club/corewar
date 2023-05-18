/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** list_process
*/

#include <stdlib.h>
#include "process.h"

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
    list->id = id;
    list->index = index;
    list->next = NULL;
    list->last_live = 0;
    return (list);
}


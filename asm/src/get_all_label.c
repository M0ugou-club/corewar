/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_all_label
*/

#include "asm.h"
#include "my.h"

int store_label(char *line)
{
    int index = 0;
    int info = 0;

    while (line[index] != '\0') {
        if (line[index] == LABEL_CHAR) {
            return (index);
        }
        info = compare_char(line[index]);
        if (info != 0) {
            return (-1);
        }
        index++;
    }
    return (index);
}

int copy_label(prog_list_t *line, int index)
{
    line->label = malloc(sizeof(char) * (index + 1));
    if (line->label == NULL) {
        return (-1);
    }
    my_memset(line->label, '\0', index + 1);
    for (int i = 0; i < index; i++) {
        line->label[i] = line->line[i];
    }
    return (0);
}

int get_all_label(prog_list_t *list)
{
    prog_list_t *tmp = list;
    int error = 0;
    int index = 0;

    while (tmp != NULL) {
        index = store_label(tmp->line);
        if (index != -1) {
            error = copy_label(tmp, index);
        }
        if (error != 0) {
            return (-1);
        }
        index = 0;
        tmp = tmp->next;
    }
    return (0);
}

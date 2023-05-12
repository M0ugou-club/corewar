/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_prog_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "prog_list.h"

//void exit_error(char *line, char *copy, prog_list_t *prog_list,
//    prog_list_t *new_node)
//{
//    if (line != NULL) {
//        free(line);
//    }
//    if (copy != NULL) {
//        free(copy);
//    }
//    if (prog_list != NULL) {
//        free_list(prog_list);
//    }
//    if (new_node != NULL) {
//        free(new_node);
//    }
//    exit(84);
//}

prog_list_t *fill_list(prog_list_t *prog_list,
    prog_list_t *new_node)
{
    prog_list_t *tmp = NULL;

    if (prog_list == NULL) {
        prog_list = new_node;
    } else {
        tmp = prog_list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    return (prog_list);
}

prog_list_t *add_node(char *copy, prog_list_t *prog_list)
{
    prog_list_t *new_node = NULL;

    if (my_strlen(copy) != 0) {
        new_node = malloc(sizeof(prog_list_t));
        if (new_node == NULL) {
            return (NULL);
        }
        new_node->next = NULL;
        new_node->line = my_strdup(copy);
        if (new_node->line == NULL) {
            return (NULL);
        }
        prog_list = fill_list(prog_list, new_node);
    }
    return (prog_list);
}

prog_list_t *get_prog_list(int fd)
{
    prog_list_t *prog_list = NULL;
    char *copy = NULL;
    char *line = NULL;
    size_t size = 0;
    int len = 0;

    while ((len = getline(&line, &size, fd)) != EOF) {
        line[len - 1] = '\0';
        copy = str_clear(line);
        if (copy == NULL) {
            return (NULL);
        }
        prog_list = add_node(line, prog_list);
        free(copy);
    }
    free(line);
    return (prog_list);
}

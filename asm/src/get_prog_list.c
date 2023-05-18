/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_prog_list
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "asm.h"
#include "my.h"

static prog_list_t *fill_list(prog_list_t *prog_list, prog_list_t *new_node)
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

static prog_list_t *add_node(char const *copy, prog_list_t *prog_list,
    bool *first_line)
{
    prog_list_t *new_node = NULL;

    if (my_strlen(copy) != 0) {
        *first_line = true;
        new_node = malloc(sizeof(prog_list_t));
        if (new_node == NULL) {
            return (NULL);
        }
        new_node->next = NULL;
        new_node->line = my_strdup(copy);
        new_node->command_int = NULL;
        new_node->line_array = NULL;
        new_node->label = NULL;
        if (new_node->line == NULL) {
            return (NULL);
        }
        prog_list = fill_list(prog_list, new_node);
    }
    return (prog_list);
}

static int remove_comment(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '#') {
            str[i] = '\0';
        }
        i++;
    }
    return (0);
}

prog_list_t *get_prog_list(FILE *fd)
{
    prog_list_t *prog_list = NULL;
    bool first_line = false;
    char *copy = NULL;
    char *line = NULL;
    size_t size = 0;
    int len = 0;

    while ((len = getline(&line, &size, fd)) != EOF) {
        line[len - 1] = '\0';
        remove_comment(line);
        copy = my_strclear(line);
        if (copy == NULL)
            return (NULL);
        prog_list = add_node(copy, prog_list, &first_line);
        if (first_line == true && prog_list == NULL)
            return (NULL);
        free(copy);
    }
    free(line);
    return (prog_list);
}

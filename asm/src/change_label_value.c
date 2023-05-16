/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** change_label_value
*/

#include <stddef.h>
#include "asm.h"
#include "my.h"

int increase_index(command_int_t *command_int)
{
    int index = 0;

    if (command_int == NULL) {
        return (index);
    }
    for (int i = 0; command_int->value_size[i] != -1 && i < MAX_LENGTH; i++) {
        index += command_int->value_size[i];
    }
    return (index);
}

static int find_label_index(prog_list_t *prog_list, prog_list_t *line, char *arg)
{
    prog_list_t *tmp = prog_list;
    int len = 0;
    int index = 0;

    len = my_strlen("%:");
    while (tmp != NULL) {
        if (my_strcmp(&arg[len], tmp->label) == 0) {
            return (index);
        }
        if (tmp->command_int != NULL) {
            index += increase_index(tmp->command_int);
        }
        tmp = tmp->next;
    }
    return (-1);
}

static int get_curr_index(prog_list_t *prog_list, prog_list_t *line)
{
    prog_list_t *tmp = prog_list;
    int index = 0;

    while (tmp != NULL && tmp != line) {
        index += increase_index(tmp->command_int);
        tmp = tmp->next;
    }
    return (index);
}

static int get_label_value(prog_list_t *prog_list, prog_list_t *line, int i)
{
    int index = 0;
    int curr_index = 0;

    if (my_strncmp(line->line, NAME_CMD_STRING,
            my_strlen(NAME_CMD_STRING)) == 0
        || my_strncmp(line->line, COMMENT_CMD_STRING,
            my_strlen(COMMENT_CMD_STRING)) == 0) {
        return (0);
    }
    if (is_label(line->line_array[i]) == 0) {
        curr_index = get_curr_index(prog_list, line);
        index = find_label_index(prog_list, line, line->line_array[i]);
        if (index == -1) {
            return (-1);
        }
        line->command_int->value[i] = index - curr_index;
    }
    i++;
    return (0);
}

int change_label_value(prog_list_t *prog_list)
{
    prog_list_t *tmp = prog_list;
    int error = 0;
    int i = 0;

    while (tmp != NULL) {
        while (tmp->line_array != NULL && tmp->line_array[i] != NULL) {
            error = get_label_value(prog_list, tmp, i);
            i++;
        }
        if (error != 0) {
            return (error);
        }
        i = 0;
        tmp = tmp->next;
    }
    return (error);
}

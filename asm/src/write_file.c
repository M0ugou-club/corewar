/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write_file
*/

#include <unistd.h>
#include "asm.h"
#include "my.h"

static int write_int(char *num, int num_size, int fd)
{
    char nb = 0;

    if (num == NULL) {
        return (-1);
    }
    for (int i = 0; i < num_size; i++) {
        nb = num[i];
        write(fd, &nb, 1);
    }
    return (0);
}

static int write_int_tab(command_int_t *command_int, int fd)
{
    char *num = NULL;

    if (command_int->value == NULL || command_int->value_size == NULL) {
        return (0);
    }
    for (int i = 0; command_int->value_size[i] != -1; i++) {
        num = command_int->value[i];
        if (write_int(num, command_int->value_size[i], fd) == -1) {
            return (-1);
        }
    }
    return (0);
}

int write_file(prog_list_t *prog_list, int fd)
{
    prog_list_t *tmp = prog_list;
    int error = 0;
    const char error_str[33] = "Cound't write the file properly\n";

    while (tmp != NULL) {
        if (tmp->command_int != NULL) {
            error = write_int_tab(tmp->command_int, fd);
        }
        if (error != 0) {
            write(2, error_str, my_strlen(error_str));
            return (-1);
        }
        tmp = tmp->next;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** load_tab
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

command_int_t *load_int_tab(void)
{
    command_int_t *command_int = NULL;

    command_int = malloc(sizeof(command_int_t));
    if (command_int == NULL) {
        return NULL;
    }
    command_int->value = malloc(sizeof(int) * MAX_LENGTH);
    command_int->value_size = malloc(sizeof(int) * MAX_LENGTH);
    if (command_int->value == NULL
        || command_int->value_size == NULL) {
        free(command_int);
        return (NULL);
    }
    my_int_memset(command_int->value, -1, MAX_LENGTH);
    my_int_memset(command_int->value_size, -1, MAX_LENGTH);
    return (command_int);
}

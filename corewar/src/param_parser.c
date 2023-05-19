/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param_parser
*/

#include <stdlib.h>
#include "my.h"
#include "vm.h"

void get_dump_value(char **av, vm_t *vm)
{
    int value = 0;

    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") && av[i + 1] != NULL) {
            value = my_atoi(av[i +1]);
        }
    }
    if (value < 0) {
        vm->f_dump = 0;
    } else {
        vm->f_dump = value;
    }
}

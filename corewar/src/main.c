/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** main.c
*/

#include <stdlib.h>
#include "vm.h"
#include "memory.h"

static int error_handling(int ac, char **argv)
{
    return 0;
}

int main(int ac, char **argv)
{
    vm_t *vm = NULL;

    if (error_handling(ac, argv) != 0) {
        return 84;
    }
    vm = malloc(sizeof(vm_t));
    if (vm) {
        vm->memory = create_memory();
        vm->f_dump = get_dump_value(argv);
    }
    return 0;
}

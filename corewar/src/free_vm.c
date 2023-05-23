/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free_mv
*/

#include <stddef.h>
#include "vm.h"

void free_vm(vm_t *vm)
{
    if (vm->memory != NULL) {
        free(vm->memory);
    }
    free(vm);
}

/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** main.c
*/

#include <stdlib.h>
#include "vm.h"
#include "mem.h"

static void free_vm(vm_t *vm)
{
    if (vm->memory != NULL) {
        free(vm->memory);
    }
    free(vm);
}

static int error_handling(int ac)
{
    if (ac < 3) {
        return 84;
    }
    return 0;
}

vm_t *initialisation_of_vm(char **argv)
{
    vm_t *vm = NULL;

    vm = malloc(sizeof(vm_t));
    if (vm) {
        vm->memory = create_memory();
        if (vm->memory == NULL) {
            free(vm);
            return (NULL);
        }
        vm->nb_champ = get_nb_champ(argv);
        vm->nb_alive = 0;
        vm->f_dump = -1;
    }
    return vm;
}

int main(int ac, char **argv)
{
    process_t *process = NULL;
    vm_t *vm = NULL;
    int return_value = 0;

    if (error_handling(ac) != 0) {
        return 84;
    }
    vm = initialisation_of_vm(argv);
    return_value = 84;
    if (vm) {
        process = param_parser(argv, vm);
        if (process) {
            return_value = my_vm(vm, process);
        }
    }
    free_champ(process);
    free_vm(vm);
    return return_value;
}

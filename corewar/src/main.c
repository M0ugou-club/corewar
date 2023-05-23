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
        vm->nb_champ = get_nb_champ(argv);
        vm->nb_alive = 0;
        vm->f_dump = get_dump_value(argv);
    }
    return vm;
}

int main(int ac, char **argv)
{
    process_t *process = NULL;
    vm_t *vm = NULL;
    int return_value = 0;

    if (error_handling(ac, argv) != 0) {
        return 84;
    }
    vm = initialisation_of_vm(argv);
    if (vm) {
        process = param_parser(argv, vm);
        if (process) {
            return_value = my_vm(vm, process);
        }
    }
    free_champ(process);
    return return_value;
}

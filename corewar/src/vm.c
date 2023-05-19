/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.c
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

static int how_many_champ_alive(const process_t *process)
{
    process_t *tmp = process;
    int champ_alive = 0;

    while (tmp) {
        if (tmp->index != -1) {
            champ_alive++;
        }
        tmp = tmp->next;
    }
    return champ_alive;
}

static int incrementation_cycle(int cycle_to_die, vm_t *vm)
{
    if (vm->nb_alive > NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
    }
    return cycle_to_die;
}

int my_vm(vm_t *vm, process_t *process)
{
    int champ_alive = 0;
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle = 0;

    if (!vm || !process) {
        return 84;
    }
    champ_alive = how_many_champ_alive(process);
    while (champ_alive > 1 && cycle_to_die > 0) {
        loop_process(vm, process);
        cycle++;
        if (cycle == cycle_to_die) {
            cycle_to_die = incrementation_cycle(cycle_to_die, vm);
            cycle = 0;
        }
        champ_alive = how_many_champ_alive(process);
    }
    return 0;
}

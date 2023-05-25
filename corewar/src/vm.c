/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.c
*/

#include "op.h"
#include "vm.h"

static int incrementation_cycle(int cycle_to_die, vm_t *vm)
{
    if (vm->nb_alive >= NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
        vm->nb_alive = 0;
    }
    return cycle_to_die;
}

int my_vm(vm_t *vm, process_t *process)
{
    int champ_alive = vm->nb_champ;
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle = 0;

    if (!vm || !process)
        return 84;
    while (champ_alive > 1 && cycle_to_die > 0 && vm->f_dump != 0) {
        loop_process(vm, process, cycle_to_die);
        cycle++;
        if (vm->f_dump > 0)
            vm->f_dump--;
        if (cycle == cycle_to_die) {
            cycle_to_die = incrementation_cycle(cycle_to_die, vm);
            cycle = 0;
        }
        champ_alive = get_nb_champ_alive(process, vm);
    }
    print_final_state(vm, process);
    return 0;
}

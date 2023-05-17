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

static int incrementation_cycle(int *champ_alive, int cycle_to_die)
{
    *champ_alive = how_many_champ_alive(process);
    if (*champ_alive > NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
    }
    return cycle_to_die;
}

int my_vm(char *memory, process_t *process)
{
    int champ_alive = 0;
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle = 0;

    if (!memory || !process) {
        return 84;
    }
    champ_alive = how_many_champ_alive(process);
    while (champ_alive > 1 && cycle_to_die > 0) {
        loop_process(process);
        cycle++;
        if (cycle == cycle_to_die) {
            cycle_to_die = incrementation_cycle(&champ_alive, cycle_to_die)
            cycle = 0;
        }
    }
}
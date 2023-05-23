/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.c
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

static int write_hexa_line(int line)
{
    char to_print = 0;

    to_print = line % 16;
    if (to_print > 9) {
        to_print += '0';
    } else {
        to_print += 'A';
    }
    if (line > 16) {
        write_hexa_line(line / 16);
    }
    write(1, &to_print, 1);
    return (0);
}

static int write_hexa_mem(int nb, int index)
{
    char to_print = 0;

    to_print = nb % 16;
    if (to_print > 9) {
        to_print += '0';
    } else {
        to_print += 'A';
    }
    if (index == 0) {
        return (0);
    } else {
        write_hexa_mem(nb / 16, index - 1);
    }
    write(1, &to_print, 1);
    return (0);
}

static int write_mem(char *memory, int line)
{
    int index_line = 32;
    int i = line;

    while (i < MEM_SIZE && index_line != 0) {
        write(1, " ", 1);
        write_hexa_mem(memory[i], 2);
        i++;
        index_line--;
    }
    write(1, "\n", 1);
    return (0);
}

static int print_final_state(vm_t *vm)
{
    int line = 0;

    if (vm->f_dump == 0) {
        while (line < MEM_SIZE) {
            write_hexa_line(line);
            write(1, "\t:", my_strlen("\t:"));
            write_mem(vm->memory, line);
            line += 32;
        }
    }
    return (0);
}

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
        cycle++;
        if (vm->f_dump > 0)
            vm->f_dump--;
        if (cycle == cycle_to_die) {
            cycle_to_die = incrementation_cycle(cycle_to_die, vm);
            cycle = 0;
        }
        champ_alive = get_nb_champ_alive(process, vm);
    }
    return 0;
}

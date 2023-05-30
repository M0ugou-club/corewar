/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_loop.c
*/

#include <stdlib.h>
#include "fonction.h"
#include "mem.h"
#include "vm.h"
#include "op.h"

static const function_t function[] = { {1, &exec_live},
{2, &exec_ld},
{3, &exec_st},
{4, &exec_add},
{5, &exec_sub},
{6, &exec_and},
{7, &exec_or},
{8, &exec_xor},
{9, &exec_zjmp},
{10, &exec_ldi},
{11, &exec_sti},
{12, &exec_fork},
{13, &exec_lld},
{14, &exec_lldi},
{15, &exec_fork},
{16, &exec_aff},
{-1, NULL}};

static int process_cooldown(process_t *process)
{
    if (process->cooldown == 0) {
        return (0);
    } else {
        process->cooldown--;
        return (1);
    }
}

static int parse_champ(vm_t *vm, process_t *process, int cycle_to_die)
{
    int return_value = 0;

    if (process->last_lives > cycle_to_die)
        process->index = -1;
    if (process->index == -1)
        return return_value;
    if (process_cooldown(process) != 0)
        return (return_value);
    process->last_lives++;
    for (int i = 0; function[i].id != -1; i++) {
        if (function[i].action &&
        vm->memory[circular_mod(process->index)] == function[i].id) {
            return_value = function[i].action(process, vm);
            process->cooldown = op_tab[i].nbr_cycles;
            return (return_value);
        }
    }
    process->index = -1;
    return return_value;
}

int loop_process(vm_t *vm, process_t *process, int cycle_to_die)
{
    process_t *tmp = process;

    if (!vm || !process)
        return -1;
    while (tmp) {
        if (parse_champ(vm, tmp, cycle_to_die) == -1) {
            return -1;
        }
        tmp = tmp->next;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** addition
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "vm.h"

int exec_live(process_t *process, vm_t *vm)
{
    int nb_champ = 0;

    nb_champ = get_value(vm->memory, process->index + 1, T_IND);
    if (nb_champ == process->nb_champ) {
        process->last_lives = 0;
    }
    return (0);
}

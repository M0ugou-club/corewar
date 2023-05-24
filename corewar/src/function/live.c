/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** addition
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "my.h"
#include "vm.h"

int write_nb(int nb)
{
    char to_print = 0;

    to_print = nb % 10 + '0';
    if (nb >= 10) {
        write_nb(nb / 10);
    }
    write(1, &to_print, 1);
    return 0;
}

int print_live(process_t *process)
{
    write(1, "The player ", 11);
    write_nb(process->nb_champ);
    write(1, " (" ,2);
    write(1, process->id, my_strlen(process->id));
    write(1, ") is alive.\n", 12);
    return 0;
}

int exec_live(process_t *process, vm_t *vm)
{
    int nb_champ = 0;

    nb_champ = get_value(vm->memory, process->index + 1, T_IND);
    if (nb_champ == process->nb_champ) {
        process->last_lives = 0;
        print_live(process);
    }
    return (0);
}

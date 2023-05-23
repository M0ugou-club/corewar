/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_nb_champ_alive
*/

#include <stddef.h>
#include "vm.h"
#include "my.h"

int is_champ_alive(process_t *process, int nb_champ)
{
    process_t *tmp = process;

    while (tmp != NULL) {
        if (my_strcmp(tmp->id, nb_champ) == 0 && tmp->index != -1) {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int get_nb_champ_alive(process_t *process, vm_t *vm)
{
    int nb_loop = vm->nb_champ;
    process_t *tmp = process;
    int alive = 0;

    for (int i = 0; i != nb_loop; i++, tmp = tmp->next) {
        alive += is_champ_alive(process, tmp->nb_champ);
    }
    return (alive);
}

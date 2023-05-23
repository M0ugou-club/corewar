/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_nb_champ
*/

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "process.h"
#include "vm.h"
#include "my.h"

int is_champ_alive(process_t *process, int nb_champ)
{
    process_t *tmp = process;

    while (tmp != NULL) {
        if (tmp->nb_champ == nb_champ && tmp->index != -1) {
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

int get_nb_champ(char **argv)
{
    int nb_champ = 0;
    int fd = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd != -1) {
            nb_champ++;
            close(fd);
        }
    }
    return (nb_champ);
}

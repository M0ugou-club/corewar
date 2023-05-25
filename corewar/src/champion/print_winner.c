/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** print winner
*/

#include <stdlib.h>
#include <unistd.h>
#include "process.h"
#include "vm.h"
#include "my.h"

int print_winner(process_t *winner)
{
    write(1, "The player ", 11);
    write_nb(winner->nb_champ);
    write(1, " (", 2);
    write(1, winner->id, my_strlen(winner->id));
    write(1, ") has won.\n", 11);
    return 0;
}

int get_winner(process_t *list_champ)
{
    process_t *winner = NULL;
    process_t *current = list_champ;
    int last_live = 0;

    if (current != NULL) {
        last_live = current->last_lives;
    }
    while (current) {
        if (current->last_lives <= last_live) {
            winner = current;
            last_live = current->last_lives;
        }
        current = current->next;
    }
    if (winner != NULL) {
        print_winner(winner);
    }
    return 0;
}

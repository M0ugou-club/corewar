/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process
*/

#ifndef PROCESS_H_
    #define PROCESS_H_
    #include "op.h"

    typedef struct process_s {
        int index;
        int cooldown;
        int last_lives;
        int *registers;
        int nb_champ;
        char *id;
        process_t *next;
    } process_t;

#endif /* !PROCESS_H_ */

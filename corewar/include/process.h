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
        char *code;
        struct process_s *next;
        int carry;
    } process_t;

#endif /* !PROCESS_H_ */

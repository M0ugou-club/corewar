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
        char *id;
        int nb_champ;
        struct process_s *next;
    } process_t;

    process_t *create_basic_process(int index, char *name, int nb_champ,
                                    process_t *process);

#endif /* !PROCESS_H_ */

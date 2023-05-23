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
        int nb_champ;
        struct process_s *next;
        int carry;
    } process_t;

    process_t *create_basic_process(int index, char *name, int nb_champ,
                                    process_t *process);
    header_t *get_header(int fd);

#endif /* !PROCESS_H_ */

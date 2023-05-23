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

    process_t *create_basic_process(char *name, process_t *process);
    int get_header(int fd, header_t *champ_header);
    char *get_prog(int fd, header_t *champ_header);

#endif /* !PROCESS_H_ */

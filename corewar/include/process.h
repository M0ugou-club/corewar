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
        char *id;
        int nb_champ;
        int *registers;
        int index;
        int cooldown;
        int last_lives;
        int carry;
        struct process_s *next;
    } process_t;

    process_t *create_basic_process(char *name, process_t *process);
    int get_header(int fd, header_t *champ_header);
    char *get_prog(int fd, header_t *champ_header);
    void free_champ(process_t *list_champ);

#endif /* !PROCESS_H_ */

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process
*/

#ifndef PROCESS_H_
    #define PROCESS_H_
    #include "op.h"

    typedef struct process
    {
        int index;
        char *id;
        int[REG_NUMBER];
        process_t *next;
    } process_t;


#endif /* !PROCESS_H_ */

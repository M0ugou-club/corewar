/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** mem
*/

#ifndef MEM_H_
#define MEM_H_

    typedef struct mem_s {
        struct mem_s *prev;
        char oct;
        struct mem_s *next;
    } mem_t;


#endif /* !MEM_H_ */

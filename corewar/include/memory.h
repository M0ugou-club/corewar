/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** memory.h
*/
#ifndef MEMORY_H_
    #define MEMORY_H_

    char *create_memory(void);
    void modif_mem(char *mem, int index, const char value);
    char get_mem_value(char *mem, int index);

#endif /*MEMORY_H_*/

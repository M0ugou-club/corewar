/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.h
*/
#ifndef VM_H_
    #define VM_H_

    #include "process.h"

    typedef struct vm_s {
        char *memory;
        int nb_alive;
        int nb_champ;
        int f_dump;
    } vm_t;

    int loop_process(vm_t *vm, process_t *process);
    int get_dump_value(char **av);
    int print_final_state(vm_t *vm);

#endif /*VM_H_*/

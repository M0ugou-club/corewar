/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.h
*/
#ifndef VM_H_
    #define VM_H_
    #define MALLOC_RETURN(ptr, ret) if (ptr == NULL) return (ret);

    #include "process.h"

typedef struct vm_s {
    char *memory;
    int nb_alive;
    int nb_champ;
    int f_dump;
} vm_t;

int loop_process(vm_t *vm, process_t *process);
int get_dump_value(char **av);
int get_nb_champ_alive(process_t *process, vm_t *vm);
int my_vm(vm_t *vm, process_t *process);
#endif /*VM_H_*/

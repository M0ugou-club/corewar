/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm.h
*/
#ifndef VM_H_
    #define VM_H_
    #define BIT_VALUE 2
    #define BYTE_VALUE 256
    #define CODYNG_BYTE_LEN 4
    #define MALLOC_RETURN(ptr, ret) if (ptr == NULL) return (ret);
    #define RETURN_ERROR(value, error, exit) if (value == error) return (exit);
    #define SWAP_ENDIAN(x) ((x >> 24) & 0xff) | ((x << 8) & 0xff0000) \
| ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
  
    /* Arg indexex*/
    #define SKIP_COMM_CB 2
    #define INDEX_1ST 0
    #define INDEX_2ND 1
    #define INDEX_3RD 2
    #define INDEX_4TH 3

    #include "process.h"

    typedef struct vm_s {
        char *memory;
        int nb_alive;
        int nb_champ;
    } vm_t;

    typedef struct type_value_s {
        char value;
        char type;
    } type_value_t;

    int loop_process(vm_t *vm, process_t *process);

#endif /*VM_H_*/

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

    /* Arg indexex*/
    #define SKIP_COMM_CB 2
    #define INDEX_1ST 0
    #define INDEX_2ND 1
    #define INDEX_3RD 2
    #define INDEX_4TH 3

    #include "process.h"
    #include "op.h"

    typedef struct vm_s {
        char *memory;
        int nb_alive;
        int nb_champ;
        int f_dump;
    } vm_t;

    typedef struct type_value_s {
        char value;
        char type;
    } type_value_t;

    int print_final_state(vm_t *vm, process_t *process_list);
    int get_nb_champ_alive(process_t *process, vm_t *vm);
    int my_vm(vm_t *vm, process_t *process);
    int put_champ(process_t *champ, vm_t *vm, char *code,
        header_t *champ_info);
    int get_nb_champ(char **argv);
    process_t *param_parser(char **av, vm_t *vm);
    int is_opt(char **av, int i, process_t *process, vm_t *vm);
    int loop_process(vm_t *vm, process_t *process, int cycle_to_die);
    int get_winner(process_t *list_champ);
    int write_nb(int nb);

#endif /*VM_H_*/

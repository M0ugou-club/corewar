/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fonction.h
*/
#ifndef FONCTION_H_
    #define FONCTION_H_

    #include <stdbool.h>
    #include "vm.h"
    #include "process.h"

    typedef struct function_s {
        char id;
        int (*action) (process_t *process, vm_t *vm);
    } function_t;


    int get_type_error(char const *cb_tab, int fct_nb);
    char *get_coding_byte(char coding_bytes);
    int get_index_arg(char coding_byte, bool index_function);
    int get_reg_error(int reg_nb);
    int get_special_value(char *memory, int index, char coding_byte,
        process_t *process);
    int get_indexes_value(char *memory, int index, char coding_byte,
        process_t *process);
    int increase_index(char *cb_tab, bool index_function);
    int get_new_process_index(char *cb_tab, bool index_function,
        process_t *process);
    int get_value(char *memory, int index, char coding_byte);
    int write_memory(char *memory, int index, int val);

    /* Function Pointer */

    int exec_sub(process_t *process, vm_t *vm);
    int exec_add(process_t *process, vm_t *vm);
    int exec_aff(process_t *process, vm_t *vm);
    int exec_fork(process_t *process, vm_t *vm);
    int exec_ld(process_t *process, vm_t *vm);
    int exec_ldi(process_t *process, vm_t *vm);
    int exec_live(process_t *process, vm_t *vm);
    int exec_lld(process_t *process, vm_t *vm);
    int exec_lldi(process_t *process, vm_t *vm);
    int exec_and(process_t *process, vm_t *vm);
    int exec_or(process_t *process, vm_t *vm);
    int exec_xor(process_t *process, vm_t *vm);
    int exec_st(process_t *process, vm_t *vm);
    int exec_sti(process_t *process, vm_t *vm);
    int exec_zjmp(process_t *process, vm_t *vm);

#endif /*FONCTION_H_*/

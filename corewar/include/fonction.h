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

    int exec_sub(process_t *process, vm_t *vm);
    int exec_add(process_t *process, vm_t *vm);
    int get_value(char *memory, int index, char coding_byte);
    int get_type_error(char const *cb_tab, int fct_nb);
    char *get_coding_byte(char coding_bytes);
    int get_index_arg(char coding_byte, bool index_function);
    int get_reg_error(int reg_nb);
    int get_special_value(char *memory, int index, char coding_byte,
        process_t *process);
    int get_indexes_value(char *memory, int index, char coding_byte,
        process_t *process);

#endif /*FONCTION_H_*/

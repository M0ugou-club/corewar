/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fonction.h
*/
#ifndef FONCTION_H_
	#define FONCTION_H_

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
    int increase_index(char *cb_tab);
    int get_reg_error(int reg_nb);

#endif /*FONCTION_H_*/
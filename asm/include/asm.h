/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #define MAX_LENGTH 6
    #define BYTE_VALUE 256
    #define MALLOC_RETURN(ptr, ret) if (ptr == NULL) return (ret);

    #include <stdio.h>
    #include "op.h"

    typedef struct format_s format_t;

    struct format_s {
        char *type;
        int bit1;
        int bit2;
    };

    /* Command */

    typedef struct prog_list_s prog_list_t;
    typedef struct command_int_s command_int_t;

    typedef struct type_s {
        char* c;
        int lenght;
    } type_t;

    struct prog_list_s {
        char *label;
        char *line;
        char **line_array;
        command_int_t *command_int;
        prog_list_t *next;
    };

    struct command_int_s {
        int *value_size;
        char **value;
    };

    prog_list_t *get_prog_list(FILE *fd);
    command_int_t *load_int_tab(void);
    int fill_multiple_args_line(command_int_t *command_int, char **line_array,
        int fnct_nbr);
    int get_format_value(char **args);
    int get_nbr_value(char **value , int *value_size, char *arg, int index);
    int process_asm(char const *file_name);
    FILE *open_file(char const *file_name);
    int compile_line(prog_list_t *line);
    int is_label(char const *arg);
    int change_label_value(prog_list_t *prog_list);
    int write_file(prog_list_t *prog_list);
    int get_line_array(prog_list_t *prog_list);
    int compare_char(char compare);
    int get_all_label(prog_list_t *list);
    int change_size_index(command_int_t *command_int);
    char *fill_char_tab(int num, int size);

#endif /* !ASM_H_ */

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
    #define RETURN_ERROR(value, error, exit) if (value == error) return(exit);
    #define SWAP_ENDIAN(x) ((x >> 24) & 0xff) | ((x << 8) & 0xff0000)\
        | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)

    #include <stdio.h>

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
        int info;
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

    typedef struct header_s header_t;

    prog_list_t *get_prog_list(FILE *fd);
    command_int_t *load_int_tab(void);
    int process_asm(char const *file_name);
    FILE *open_file(char const *file_name);
    int compile_line(prog_list_t *line);
    int is_label(char const *arg);
    int change_label_value(prog_list_t *prog_list);
    int write_file(prog_list_t *prog_list, int fd);
    int get_line_array(prog_list_t *prog_list);
    int compare_char(char compare);
    int get_all_label(prog_list_t *list);
    char *fill_char_tab(int num, int size);
    int increase_index(command_int_t *command_int);
    int get_line_array(prog_list_t *prog_list);
    int open_new_file(char const *file_name);
    int compil_header(prog_list_t *file, header_t *header, int size);
    int get_curr_index(prog_list_t *prog_list, prog_list_t *line);
    int error_compil(char **line_array, int fct_nb);

#endif /* !ASM_H_ */

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
    #define RETURN_ERROR(value, error, exit) if (value == error) return (exit);
    #define SWAP_ENDIAN(x) ((x >> 24) & 0xff) | ((x << 8) & 0xff0000) \
| ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
    #define REG_INDEX 0
    #define SKIP_COMMAND 1

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

    int process_asm(char const *file_name);

    /* File management */
    FILE *open_file(char const *file_name);
    int open_new_file(char const *file_name);
    int write_file(prog_list_t *prog_list, int fd);

    /* Utils*/
    char *fill_char_tab(int num, int size, int i);
    int get_curr_index(prog_list_t *prog_list, prog_list_t *line);
    int get_str(char const *line, char str[]);
    int get_line_array(prog_list_t *prog_list);
    int compare_char(char compare);
    int increase_index(command_int_t *command_int);
    void free_prog_list(prog_list_t *prog_list);
    void free_tab(char **tab);

    /* Compil */
    prog_list_t *get_prog_list(FILE *fd);
    int compil_header(prog_list_t *file, header_t *header, int size);
    int compile_line(prog_list_t *line);
    int error_compil(char **line_array, int fct_nb);

    /* Label management */
    int get_all_label(prog_list_t *list);
    int change_label_value(prog_list_t *prog_list);
    int is_label(char const *arg);
    int is_only_label_line(char const *arg);

#endif /* !ASM_H_ */

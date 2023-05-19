/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    int my_strlen(char const *str);
    char *my_strdup(char const *str);
    int my_memset(char *str, char byte, int len);
    char *my_strclear(char const *str);
    int my_atoi(const char *str);
    int my_strcmp(char const *str1, char const *str2);
    int my_strncmp(char const *str1, char const *str2, int n);
    int my_power(int nb, int power);
    int my_str_is_num(char const *str);
    int my_int_memset(int *tab, int byte, int len);
    char **str_to_array(char const *str, char delim);
    int my_tab_memset(char **data, char *byte, int len);
    int my_strncat(char *dest, char const *src, int len);
    int my_strcat(char *dest, char const *src);
    int my_strncpy(char *dest, char const *src, int len);
    int my_strcpy(char *dest, char const *src);
    int my_putstr(char const *str, int output);
    int my_tablen(char **tab);

#endif /* !MY_H_ */

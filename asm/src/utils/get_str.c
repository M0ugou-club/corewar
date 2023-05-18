/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_str
*/

int get_str(char const *line, char str[])
{
    int quote_status = -1;
    int index = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (quote_status == 1 && line[i] != '\"') {
            str[index] = line[i];
            index++;
        }
        if (line[i] == '\"') {
            quote_status *= -1;
        }
    }
    return (0);
}

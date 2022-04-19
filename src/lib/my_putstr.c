/*
** EPITECH PROJECT, 2018
** PutSTR
** File description:
** Fonction putstr
*/

#include <unistd.h>
#include <string.h>

int my_putstr(char const *str)
{
    if (str == NULL)
        return 0;
    write(1, str, strlen(str));
    return (0);
}

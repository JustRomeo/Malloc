/*
** EPITECH PROJECT, 2018
** PutNbr
** File description:
** Fonction PutNbr
*/

#include <unistd.h>
#include <string.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nbr)
{
    int i = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 0) {
        if (nbr >= 10) {
            i = (nbr % 10);
            nbr = (nbr - i) / 10;
            my_put_nbr(nbr);
            my_putchar(48 + i);
        }
        else
            my_putchar(48 + nbr % 10);
    }
    return (0);
}

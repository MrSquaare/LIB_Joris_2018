/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** LIB_MyLIB_2018
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int len_d = 0;
    int len_s = 0;

    if (!dest || !src)
        return (dest);
    len_d = my_strlen(dest);
    len_s = my_strlen(src);
    for (int i = 0; i < len_s; ++i)
        dest[len_d + i] = src[i];
    dest[len_d + len_s] = '\0';
    return (dest);
}
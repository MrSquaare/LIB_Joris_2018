/*
** EPITECH PROJECT, 2019
** file_get.c
** File description:
** LIB_Joris_2018
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "json.h"
#include "joris_file.h"

json_object *joris_file_get(char *path)
{
    json_object *json = NULL;
    struct stat st = {0};
    int fd = 0;
    char *buffer = NULL;

    if (path) {
        fd = stat(path, &st);
        if (fd != -1) {
            buffer = malloc(sizeof(char) * (st.st_size + 1));
            fd = open(path, O_RDONLY);
            read(fd, buffer, st.st_size);
            buffer[st.st_size] = '\0';
            json = json_tokener_parse(buffer);
        }
        close(fd);
    }
    free(buffer);
    return (json);
}
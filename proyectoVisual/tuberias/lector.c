#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char leido[100];
    int desLectura;
    desLectura = open( "./tuberia", O_RDONLY );
    read( desLectura, leido, 100 * sizeof(char) );
    fprintf( stdout, "%s\n", leido );
    close( desLectura );
    return 0;
}

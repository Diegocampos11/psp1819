#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    char leido[100];
    pipe(fd);
    close( fd[1] );//Se cierra por que voy a trabajar solo en el de lectura, que es 0
    read( fd[0], leido, 100 * sizeof(char) );
    fprintf( stdout, "%s\n", leido );
    close( fd[0] );
    return 0;
}

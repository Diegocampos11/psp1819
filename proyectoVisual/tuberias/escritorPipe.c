#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char* frase = "Hola soy el escritor";
    int fd[2];//filedescriptor
    pipe(fd);
    close( fd[0] );//Cierro f0 por que voy a escribir
    long int caracteresEscritos = write( fd[1], frase, strlen( frase ) * sizeof(char) );
    fprintf( stdout, "Escritos: %ld\n", caracteresEscritos );
    close( fd[1] );
    return 0;
}

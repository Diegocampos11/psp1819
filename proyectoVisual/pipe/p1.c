#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    int tub[2];
    int entrada = tub[1];
    int salida = tub[0];

    pipe( tub );

    pid_t pidH1, pidH2;
    pidH1 = fork();//creo un hijo
    if ( pidH1 == -1 ){
        fprintf( stderr, "Error en el fork H1" );
        exit(-1);
    }
    if ( pidH1 == 0 ){//hijo 1 escribira un entero
        int msj = 123;
        write( entrada, &msj, sizeof( int ) );//donde, que es lo que mando, y que tamaño tiene!!
    }
    return 0;
}
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>

void sigUsrHandle( int );

int main(int argc, char const *argv[])
{   //sigUsr handle
    if ( signal( SIGUSR1, sigUsrHandle ) == SIG_ERR ){
        fprintf( stderr, "File : "__FILE__" Error al establecer señal SIGUSR1 : %s : Line %d\n", strerror( errno ), __LINE__ );
    }
    //
    char frase[100];
    int descriptorEscritura;
    descriptorEscritura = open( "./tuberia", O_WRONLY );
    if ( descriptorEscritura == -1 ){
        fprintf( stderr, "File : "__FILE__" Error al abrir tuberia : %s : Line %d\n", strerror( errno ), __LINE__ );
        return -1;
    }
    pid_t miPid = getpid();
    write( descriptorEscritura, &miPid, sizeof( pid_t ) );
    while (1){
        scanf( "%s", frase );
        //frase[ strlen( frase ) + 1 ] = '\0';//concateno el barra 0 en mi cadena
        printf( "Frase enviada con éxito!!\n" );
        write( descriptorEscritura, frase, (strlen( frase )+1) * sizeof(char));//tambien se debe enviar el barra 0 :D
    }
    close( descriptorEscritura );
    return 0;
}

void sigUsrHandle( int signall ){
    printf( "Recibido una señal USR del receptor\n" );
}
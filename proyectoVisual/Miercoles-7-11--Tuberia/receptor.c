#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>

pid_t pidEmisor;

void sigIntHandle( int );

int main(int argc, char const *argv[])
{
    //sigint handle
    signal( SIGINT, sigIntHandle );
    //
    char leido[100];
    int desLectura;
    desLectura = open( "./tuberia", O_RDONLY );
    if ( desLectura == -1 ){
        fprintf( stderr, "File : "__FILE__" Error al abrir tuberia : %s : Line %d\n", strerror( errno ), __LINE__ );
        return -1;
    }
    FILE* fEscritura = fopen( "./receptorCadenas.txt", "w" );
    if ( fEscritura == NULL ){
        fprintf( stderr, "File : "__FILE__" Error al abrir receptorCadenas.txt : %s : Line %d\n", strerror( errno ), __LINE__ );
        return -1;
    }
    read( desLectura, &pidEmisor, sizeof( pid_t ) );
    while(1){
        read( desLectura, leido, 100 * sizeof( char ) );
        fputs( leido, fEscritura );
        printf("Leido: %s\n", leido );
    }
    fclose( fEscritura );
    close( desLectura );
    return 0;
}

void sigIntHandle( int signall ){
    printf( "pid emisor: %d\n", pidEmisor );
    kill( pidEmisor, SIGUSR1 );
    sleep( 2 );
    kill( pidEmisor, SIGINT );
    printf( "Presoina CTRL + C para salir\n" );
    signal( SIGINT, SIG_DFL );
}
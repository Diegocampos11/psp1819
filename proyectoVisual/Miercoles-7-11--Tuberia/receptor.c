#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>

pid_t pidEmisor;
//FILE* fEscritura;
bool salirPrograma = false;

void sigIntHandle( int );

int main(int argc, char const *argv[])
{
    //sigint handle
    signal( SIGINT, sigIntHandle );
    //
    int readTub;
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
    readTub = read( desLectura, &pidEmisor, sizeof( pid_t ) );
    while( ! salirPrograma ){
        readTub = read( desLectura, leido, 100 * sizeof( char ) );
        printf( "lectura de receptor: %d", readTub );
        if ( readTub != 0 ){
            fputs( leido, fEscritura );
            fputc( '\n', fEscritura );//jump
            printf("Leido: %s\n", leido );
        }
    }
    fclose( fEscritura );
    close( desLectura );
    printf( "Emisor cerrado y receptor terminado!!\n" );
    return 0;
}

void sigIntHandle( int signall ){
    printf( "pid emisor: %d\n", pidEmisor );
    kill( pidEmisor, SIGUSR1 );
    sleep( 2 );
    kill( pidEmisor, SIGINT );
    salirPrograma = true;
    printf( "Presoina CTRL + C para salir\n" );
    //fclose( fEscritura );
    //printf( "Fichero cerrado!!\n" );
    signal( SIGINT, SIG_DFL );
}
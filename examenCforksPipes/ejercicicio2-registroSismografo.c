#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <regex.h>
#include <time.h>
#include <signal.h>

void rellenarFechaYHora(char *);

void tratarSenyal( int );

int main(){
    signal( SIGUSR1, tratarSenyal );
    signal( SIGUSR2, tratarSenyal );
    signal( SIGINT, tratarSenyal );int i = 1;
    while( 1 ){
        printf( "Diegooo!! %d\n", i++ );
        sleep(1);
    }
    return 0;
}

void tratarSenyal( int numSignal ){
    //procedo a escribir en log.txt
    FILE* fEscritura = fopen( "./log.txt", "a+" );
    if ( fEscritura == NULL ){
        fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo abrir log.txt : %s\n", __LINE__, strerror( errno ) );
        exit(EXIT_FAILURE);
    }
    char fechaHora[100];
    rellenarFechaYHora( fechaHora );
    char resForLog[100];
    if ( numSignal == SIGUSR1 ){
        int posError = sprintf( resForLog, "*%s Temblor leve detectado\n", fechaHora );
        if ( posError <= -1 ){//devuelve un numero negativo
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo ejecutar sprintf : %s\n", __LINE__, strerror( errno ) );
            exit(EXIT_FAILURE);
        }
        int errorEscritura = fputs( resForLog, fEscritura );
        if ( errorEscritura <= 0 ){
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo escribir en log.txt\n", __LINE__ );
            exit(EXIT_FAILURE);
        }
    }
    else if ( numSignal == SIGUSR2 ){
        int posError = sprintf( resForLog, "**%s Temblor FUERTE detectado\n", fechaHora );
        if ( posError <= -1 ){//devuelve un numero negativo
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo ejecutar sprintf : %s\n", __LINE__, strerror( errno ) );
            exit(EXIT_FAILURE);
        }
        int errorEscritura = fputs( resForLog, fEscritura );
        if ( errorEscritura <= 0 ){
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo escribir en log.txt\n", __LINE__ );
            exit(EXIT_FAILURE);
        }
    }
    else if ( numSignal == SIGINT ){
        int posError = sprintf( resForLog, "***%s Error en el sismógrafo\n", fechaHora );
        if ( posError <= -1 ){//devuelve un numero negativo
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo ejecutar sprintf : %s\n", __LINE__, strerror( errno ) );
            exit(EXIT_FAILURE);
        }
        int errorEscritura = fputs( resForLog, fEscritura );
        if ( errorEscritura <= 0 ){
            fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo escribir en log.txt\n", __LINE__ );
            exit(EXIT_FAILURE);
        }
    }
    fclose( fEscritura );//cierro fichero luego de escribir xd
    fflush(NULL);
    printf("Padre: Escritura realizada con éxito!!\n");
}

void rellenarFechaYHora(char *cadena){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int posError = sprintf(cadena ,"%2d/%2d/%4d (%d:%d:%d) -", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    if ( posError <= -1 ){//devuelve un numero negativo
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error (rellenarFechaYHora): no se pudo ejecutar sprintf : %s\n", __LINE__, strerror( errno ) );
        exit(EXIT_FAILURE);(EXIT_FAILURE);(EXIT_FAILURE);
    }
}
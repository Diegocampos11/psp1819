#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void tratarSenyal( int );

int main(int argc, char const *argv[])
{
    signal( SIGINT, tratarSenyal );
    signal( SIGTSTP, tratarSenyal );
    int i = 1;
    while( 1 ){
        printf( "Diegooo!! %d\n", i++ );
        sleep(1);
    }
    return 0;
}

void tratarSenyal( int numSignal ){
    char zC = 'Z';
    if ( numSignal == 2 ) zC = 'C';
    //else zC = ''
    printf( "Has presionado Control + %c ::número: %d\n", zC, numSignal );
    //printf( "He recibido una señal con número %d\n", numSignal );
    fflush(NULL);
    sleep(1);
}
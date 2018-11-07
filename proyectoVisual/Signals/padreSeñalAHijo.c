#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

void tratarSigInt( int );

//pid_t pid;

int main(int argc, char const *argv[])
{
    signal( SIGINT, tratarSigInt );
    printf("PADRE: pid: %d\n", getpid());
    pid_t pid;//pid;
    pid = fork();
    if ( pid == -1 ) perror("Error ene l fork\n");
    if ( pid == 0 ){//Hijo!! manda a padre señal control + c
        printf( "HIJO: pid: %d\n", getpid() );
        kill( getppid(), SIGINT );
    }
    else{//PADRE!!! manda a hijo señal control + c
        //printf( "PADRE: pid: %d\n", getpid());
        kill( pid, SIGINT );
        //wait(NULL);
        pause();
    }

    return 0;
}

void tratarSigInt( int numSignal ){
    printf("He recibido señal %d... soy %d\n", numSignal, getpid());
}
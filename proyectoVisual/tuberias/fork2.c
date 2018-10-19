#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid;//depende del sistema operativo
    int a = 01;//se duplican las variablessss :O
    pid = fork();
    if ( pid == -1 ){
        fprintf( stderr, "Error en el fork" );
        exit(-1);
    }
    else if ( pid == 0 ){
        /*codigo hijo*/
        printf( "HIJO y mi pid es: %d\n", getpid() );
        a++;
        //printf( "num %d\n", a );
        //sleep(1);
        pid_t nieto;
        if ( nieto = fork() == -1 ) exit(-1);
        if ( nieto == 0 )/*soy nieto*/{
            printf( "Soy el nieto %d y mi padre es %d\n", getpid(), getppid() );
            return 0;//Termina el proceso del hijo
        }
        else printf( "Hijoo y mi padre es %d\n", getppid() );
    }
    else{
        /*codigo padre*/
        //wait(NULL);
        printf( "PRINCIPAL y mi pid es: %d\n", getpid() );
        a--;
        printf( "num %d\n", a );
        return 0;
    }
    /*ejecuta todos, no*/
    //sleep(5);
    //printf( "TODOS pid: %d\n", getpid() );
    //printf( "TODOS %d\n", a );
}

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t proceso;
    for( int i = 0; i <= 1; i++ ){
        proceso = fork();
        if ( proceso == -1 ) exit(-1);
        else if ( proceso == 0 ){
            printf( "Hproceso, número: %d e i %d... padre es: %d\n", getpid(), i, getppid() );
            return 0;//Termina el proceso del hijo
        }
        else printf( "Pproceso, número: %d y i %d... padre es: %d\n", getpid(), i, getppid() );
    }
}

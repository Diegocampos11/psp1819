#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int tub[2];

    pipe( tub );
    
    int entrada = tub[1];
    int salida = tub[0];

    pid_t pidH1, pidH2;
    pidH1 = fork();//creo un hijo
    if ( pidH1 == -1 ){
        fprintf( stderr, "Error en el fork H1" );
        exit(-1);
    }
    if ( pidH1 == 0 ){//hijo 1 escribira un entero
        int msj = 123;
        printf( "H1: Enviando entero %d por el pipe...", msj );
        fflush(stdout);
        write( entrada, &msj, sizeof( int ) );//donde, que es lo que mando, y que tamaño tiene!!
        /*la funcion write devuelve el nunmero de bytes escritos
        no he escrito nada por que no cabe nada pero no es mi problema*/
        printf( "H1: hecho!!\n" );
    }
    else{
        pidH2 = fork();//creamos el segundo hijo por que el padre tendra dos hijos, seran hermanos!! :D
        if ( pidH2 == -1 ){
            fprintf( stderr, "Error en el fork H2" );
            exit(-1);
        }
        if ( pidH2 == 0 ){//hijo 2
            int msj_recibido;
            printf("H2: Recibiendo entero por el pipe...");
            sleep(1);
            read( salida, &msj_recibido, sizeof(int) );
            printf("H2: Hecho. He leído %d del pipe\n", msj_recibido);
        }
        else{//padre otra vez
            printf("Esperando a un hijo...");
            wait(NULL);//LLEGA a esta linea y verifica si hay procesos creados por el para esperar cualquiera de ellos
            printf("Padre: Hecho!!\n");
            printf("Padre: esperando a otro hijo...");
            wait(NULL);
            printf("Padre: hecho!!\n");
        }
    }
    return 0;
}
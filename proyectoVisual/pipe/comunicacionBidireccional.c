#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int tubPH[2]/*PADRE a HIJO*/, tubHP[2]/*HIJO a PADRE!! :D*/;

    pipe( tubPH );//Iniciar los pipes
    pipe( tubHP );

    pid_t pidH;
    pidH = fork();//creo un hijo
    if ( pidH == 0 ){//Hijo
        //el hijo espera hasta que el padre comience la comunicación
        close( tubPH[1] );//Cerramos la parte de escritura ya que no lo usare.. como hijo
        close( tubHP[0] );//Cerramos la parte de lectura ya que no lo usuare por que yo voy a leer
        int recibido;
        read( tubPH[0], &recibido/*para que escriba ahi dentro*se le pasa la direccion de memoria**/, sizeof(int) );
        printf( "Lectura de padre a hijo: %d\n", recibido );
        int enviar = 7;
        write( tubHP[1], &enviar, sizeof(int) );//escribo en tubHP :D
    }
    else if ( pidH == -1 ) fprintf( stderr, "error fork hijo" );
    else{///padre
        close ( tubPH[0] );//ya que yo voy a escribir de tubPH :D
        close( tubHP[1] );//Ya que solo voy a leer de tubHP :D
        int enviar = 15;
        write( tubPH[1], &enviar, sizeof(int) );
        int recibido;
        read( tubHP[0], &recibido /*& ya que le envio la direccion de memoria para que el ESCRIBAAAA*/, sizeof(int) );
        printf( "Lectura de hijo a padre: %d\n", recibido );
        wait(NULL);//Espera a que un hijo termine :D
    }
    return 0;
}
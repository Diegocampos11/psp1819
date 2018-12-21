
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#define TAM_MAX 4

int getIndexElement(char*, char*[],int);

int main(){
    char notaIngresada[TAM_MAX];
    char* escala[]={"Do","Do#","Re","Re#","Mi","Fa","Fa#","Sol","Sol#","La","Si"};
    int nElems = sizeof(escala)/sizeof(escala[0]);
    //printf("%d\n", getIndexElement("Fa#",escala,nElems));
    printf( "Ingresa la nota musical:\n" );
    char* posFError = fgets( notaIngresada, TAM_MAX, stdin );
    if ( posFError == NULL ){//apunta a null
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar fgets\n", __LINE__ );
        return -1;
    }
    if ( notaIngresada[ strlen( notaIngresada ) - 1 ] != '#' ) notaIngresada[ strlen( notaIngresada ) - 1 ] = '\0';//cuando NO es sostenida si lee el salto de linea, por lo tanto lo debo de quitar cuando no es sostenida
    
    //Hijos
    int tub[2];//enviar y recibir resultados
    pipe( tub );//Iniciar pipe
    pid_t pid1 = fork();
    if ( pid1 == -1 ) fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar el fork : %s\n", __LINE__, strerror( errno ) );
    else if ( pid1 == 0 ){//Hijo11!! :D
        //calcular la siguiente nota...
        int posPrimera = getIndexElement( notaIngresada, escala, nElems);
        int posSegunda = ( posPrimera + 4 ) % 12;//posicion segunda nota
        char* segundaNota;
        segundaNota = escala[ posSegunda ];
        //printf("%sS\n", segundaNota);
        close ( tub[0] );//ya que yo voy a escribir en tub :D
        int posError = write( tub[1], segundaNota, sizeof(char) * strlen(segundaNota) );//se le envia un puntero y el sizeof para saber cuanto debe de ESCRIBIR a partir de esa direccion de memoria :D
        if ( posError == -1 ){
            fprintf( stderr, "Hijo: File : "__FILE__" : Line : %d : Error: no se pudo escribir el resultado en la tuberia : %s\n", __LINE__, strerror( errno ) );
            return -1;
        }
        close( tub[1] );//cierro extremo escritura
    }
    else{//padre
        //Segundo hijo... tercera nota
        char terNotaP[TAM_MAX];
        
        int tub2[2];//enviar y recibir resultados
        pipe( tub2 );//Iniciar pipe
        pid_t pid2 = fork();
        if ( pid2 == -1 ) fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar el fork : %s\n", __LINE__, strerror( errno ) );
        else if ( pid2 == 0 ){//Hijo2!! :D
            //calcular la siguiente nota...
            char* terNota;
            int posPrimera = getIndexElement( notaIngresada, escala, nElems);
            if ( posPrimera == -1 ){
                printf("Nota no encontrada, fin del programa\n");
                exit( EXIT_FAILURE );
            }
            int posTercera = ( posPrimera + 7 ) % 12;//posicion segunda nota
            terNota = escala[ posTercera ];
            close ( tub2[0] );//ya que yo voy a escribir en tub :D
            int posError = write( tub2[1], terNota, sizeof(char) * strlen( terNota ) );//se le envia un puntero y el sizeof para saber cuanto debe de ESCRIBIR a partir de esa direccion de memoria :D
            if ( posError == -1 ){
                fprintf( stderr, "Hijo: File : "__FILE__" : Line : %d : Error: no se pudo escribir el resultado en la tuberia : %s\n", __LINE__, strerror( errno ) );
                return -1;
            }
            close( tub2[1] );//cierro extremo escritura
        }
        else{//padre
            close( tub2[1] );//cierro extremo escritura
            int posError = read( tub2[0], &terNotaP, sizeof(char) * TAM_MAX );//se le envia un puntero y el sizeof para saber cuanto debe de LEER a partir de esa direccion de memoria :D
            if ( posError == -1 ){
                fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo leer el resultado de la tuberia : %s\n", __LINE__, strerror( errno ) );
                return -1;
            }
            printf("Padre: Datos leidos con éxito. Tuberia sin nombre cerrada con éxito\n");
            if ( terNotaP[ strlen( terNotaP ) - 1 ] != '#' ) terNotaP[ strlen( terNotaP ) - 1 ] = '\0';
            else terNotaP[ strlen( terNotaP ) - 1 ] = '\0';
            close( tub2[0] );//cierro extremo lectura
        
            //lectura de segunda nota
            close( tub[1] );//cierro extremo escritura
            char segundaNota[TAM_MAX];
            posError = read( tub[0], &segundaNota, sizeof(char) * TAM_MAX );//se le envia un puntero y el sizeof para saber cuanto debe de LEER a partir de esa direccion de memoria :D
            if ( posError == -1 ){
                fprintf( stderr, "Padre: File : "__FILE__" : Line : %d : Error: no se pudo leer el resultado de la tuberia : %s\n", __LINE__, strerror( errno ) );
                return -1;
            }
            close( tub[0] );//cierro extremo lectura
            printf("Padre: Datos leidos con éxito. Tuberia sin nombre cerrada con éxito\n");
            printf("%c\n", segundaNota[ strlen( segundaNota ) - 2 ]);
            if ( segundaNota[ strlen( segundaNota ) - 1 ] != '#' ) segundaNota[ strlen( segundaNota ) - 1 ] = '\0';
            else segundaNota[ strlen( segundaNota ) - 1 ] = '\0';
            
            //imprimo resultado!!
            printf( "La nota completa es: %s %s %s\n", notaIngresada, segundaNota, terNotaP );
            
        }
    }
}

int getIndexElement(char* cadenaBuscada, char* array[],int nElems){
    int i;
    for( i = 0; i < nElems; i++ ){
        //printf("%s\n", cadenaBuscada);
        if ( strcmp( cadenaBuscada, array[ i ] ) == 0 ){
            //printf("encontgrado\n");
            return i;//devuelvo indice
        }
    }
    //printf("NOencontgrado\n");
    return -1;//nota no encontrada
}
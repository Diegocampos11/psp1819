#include "libComun.h"
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

/*
funciones como write or read en el manual dice se le asigna el valor apropiado al error
...
On error, -1 is returned, and errno is set appropri‐
       ately.   In  this  case it is left unspecified whether the file
       position (if any) changes.

funciones como sprintf, fputs, fputs... no especifica si lo hacen o no...
*/

bool opValido();//comprueba operador

int main(int argc, char const *argv[])
{
    if ( argc != 2 ){
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: debe proporcionar el nombre del FIFO y nada más\n", __LINE__ );
        return -1;
    }
    printf("Bienvenido a Cal by Diego Campos.\nRESULTADO = NÚMERO A (OPERACIÓN) NÚMERO B\nPrograma principal\n");
    while( getNum( 'A' ) );//infinito hasta- validar el numero ingresado
    while( opValido() );//infinito hasta- valildar operador
    printf("Abriendo tuberia\n");
    int descriptorEscritura = open( argv[1], O_WRONLY );
    if ( descriptorEscritura == -1 ){
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo abrir tuberia : %s\n", __LINE__, strerror( errno ) );
        return -1;
    }
    int posError = write( descriptorEscritura, &numDouble, sizeof( numDouble ) );
    if ( posError == -1 ){
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo escribir double en la tuberia : %s\n", __LINE__, strerror( errno ) );
        return -1;
    }
    posError = write( descriptorEscritura, operacion, sizeof( char ) );
    if ( posError == -1 ){
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo escribir la operacion en la tuberia : %s\n", __LINE__, strerror( errno ) );
        return -1;
    }
    close( descriptorEscritura );//cierro tuberia
    printf("Datos enviados con éxito. Tuberia cerrada con éxito\nEsperando resultado...\n");
    int desLectura = open( argv[1], O_RDONLY );//Abro tuberia en modo lectura :D
    posError = read( desLectura, &numDouble, sizeof( numDouble ) );
    if ( posError == -1 ){
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo leer el resultado de la tuberia : %s\n", __LINE__, strerror( errno ) );
        return -1;
    }
    close(desLectura);
    printf("Datos leidos con éxito. Tuberia cerrada con éxito\n");
    printf("Resultado: %lf\n", numDouble );
    printf("Fin del programa. Chaoo!!\n");
    return 0;
}

bool opValido(){
    regex_t regex;
    int resRegex;
    printf("Ingresa el operador ('+', '-', '*' ó '/'):\n");
    char* posError = fgets( operacion, TAM_MAX, stdin );
    if ( posError == NULL ){//apunta a null
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar fgets\n", __LINE__ );
        return -1;
    }
    resRegex = regcomp( &regex, "^[+,*,/]\n$", REG_EXTENDED );//[\x2B,\x2D,*,/]\n$ escapa +=\x2B... "escapar '-'=\x2D" JAJAJA
    if ( resRegex ) {
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: no pudo compilar regex\n", __LINE__ );
        //return false;
        exit(EXIT_FAILURE);
    }
    
    /* Execute regular expression */
    resRegex = regexec(&regex, operacion, 0, NULL, 0);
    //                escapo caracter de resta -
    if ( ! resRegex || ( operacion[0] == '-' && operacion[1] == '\n' ) ) return false;
    else if (resRegex == REG_NOMATCH) {
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: operador ingresado inválido\n", __LINE__);
        return true;
    }
    else {
        regerror(resRegex, &regex, operacion, sizeof(operacion) );//se utiliza la misma variable para mostrar el error
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: regex no pudo ejecutar el match correctamente : %s\n", __LINE__, operacion);//original text: Regex match failed:
        //return false;
        exit(EXIT_FAILURE);
    }
    
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    
    /*printf("Ingresa el operador:\n");//('+', '-', '*' ó '/')... se ve mejor solo cuando se produce el error
    fgets( operacion, TAM_MAX, stdin );
    if ( operacion[0] == '/' || operacion[0] == '+' || operacion[0] == '-' || operacion[0] == '*' ) return false;
    else{
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: operador ingresado inválido\nSolamente se admiten las siguientes operaciones:\n'+', '-', '*' ó '/'\n");
        return true;
    }*/
}
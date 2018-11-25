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

bool opValido();//comprueba operador

int main(int argc, char const *argv[])
{
    if ( argc != 2 ){
        fprintf( stderr, "Error: debe proporcionar el nombre del FIFO y nada más\n" );
        return -1;
    }
    printf("Bienvenido a Cal by Diego Campos.\nRESULTADO = NÚMERO A (OPERACIÓN) NÚMERO B\nPrograma principal\n");
    while( getNum( 'A' ) );//infinito hasta- validar el numero ingresado
    while( opValido() );//infinito hasta- valildar operador
    printf("Abriendo tuberia\n");
    int descriptorEscritura = open( argv[1], O_WRONLY );
    if ( descriptorEscritura == -1 ){
        fprintf( stderr, "File : "__FILE__" Error al abrir tuberia : %s : Line %d\n", strerror( errno ), __LINE__ );
        return -1;
    }
    write( descriptorEscritura, &numDouble, sizeof( numDouble ) );
    write( descriptorEscritura, operacion, sizeof( char ) );
    close( descriptorEscritura );//cierro tuberia
    printf("Datos enviados con éxito. Tuberia cerrada con éxito\nEsperando resultado...\n");
    int desLectura = open( argv[1], O_RDONLY );//Abro tuberia en modo lectura :D
    read( desLectura, &numDouble, sizeof( numDouble ) );
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
    fgets( operacion, TAM_MAX, stdin );
    resRegex = regcomp(&regex, "^[+,*,/]\n$", REG_EXTENDED);//[\x2B,\x2D,*,/]\n$ escapa +=\x2B... "escapar '-'=\x2D" JAJAJA
    if ( resRegex ) {
        fprintf(stderr, "Error: no pudo compilar regex\n");
        return false;
    }
    
    /* Execute regular expression */
    resRegex = regexec(&regex, operacion, 0, NULL, 0);
    //                escapo caracter de resta -
    if ( ! resRegex || ( operacion[0] == '-' && operacion[1] == '\n' ) ) return false;
    else if (resRegex == REG_NOMATCH) {
        fprintf(stderr, "Error: operador ingresado inválido\n");
        return true;
    }
    else {
        regerror(resRegex, &regex, operacion, sizeof(operacion) );//se utiliza la misma variable para mostrar el error
        fprintf(stderr, "Error: regex coincidencia fallida: %s\n", operacion);
        return false;
        //exit(1);
    }
    
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    
    /*printf("Ingresa el operador:\n");//('+', '-', '*' ó '/')... se ve mejor solo cuando se produce el error
    fgets( operacion, TAM_MAX, stdin );
    if ( operacion[0] == '/' || operacion[0] == '+' || operacion[0] == '-' || operacion[0] == '*' ) return false;
    else{
        fprintf(stderr, "Error: operador ingresado inválido\nSolamente se admiten las siguientes operaciones:\n'+', '-', '*' ó '/'\n");
        return true;
    }*/
}
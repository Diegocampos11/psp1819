#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

#define TAM_MAX 50

double numValidado();

int main(int argc, char const *argv[])
{
    char operacion;
    printf("Bienvenido a Cal by Diego Campos.\nRESULTADO = NÚMERO A (OPERACIÓN) NÚMERO B\nPrograma principal\nIngresa el número A:\n");
    double numero = numValidado();
    printf("%lf",numero);
    //double numero = atof(numIngresado[ strlen(numIngresado) - 1 ]);
    printf("Ingresa el operador:\n");
    fgets( &operacion, 1, stdin );
    printf("%c:\n", operacion);
    if ( operacion == '/' || operacion == '+' || operacion == '-' || operacion == '*' ){
        printf("%lfyeah\n", numero);
    }
    else printf("Error: operador ingresado inválido\n");
    return 0;
}

double numValidado(){
    char numIngresado[TAM_MAX];
    fgets( numIngresado, TAM_MAX, stdin );//scanf(%f%*c);lee el float y luego descarta cualquier valor
    double numero = atof( numIngresado );
    return numero;
}
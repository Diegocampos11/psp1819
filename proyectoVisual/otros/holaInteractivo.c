#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char keyOut[] = "salir";
    char nombre[15];
    fprintf( stdout, "Ingrese su nombre:\n" );
    fscanf( stdin, "%s", nombre );//Nombre equivale a la primera direccion de memoria &nombre[0]=nombre
    while ( strcmp( keyOut, nombre ) != 0 ){
        fprintf( stdout, "Hola %s, tu inicial es: %c\n", nombre, nombre[0] );
        fprintf( stdout, "Ingrese su nombre:\n" );
        fscanf( stdin, "%s", nombre );//Nombre equivale a la primera direccion de memoria &nombre[0]=nombre
        //%d define el tamaño de un entero, si coincide ambos tamaños (el tipo de tamaño leido y el de la variable) sirve :D
        //el ultimo caracter de una cadena es '\n'
        //por lo tanto puedo meter 14 caracteres
    }
    return 0;
}

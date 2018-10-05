#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];//Almacenara el mensaje
    fprintf( stdout, "Ingrese un mensaje:" );
    scanf( "%s", string );//Se asigna el valor a la variable
    FILE* file = fopen( "./ejer1.txt", "w" );//Abrimos el fichero para escribir
    fwrite( string, sizeof(char), 4, file );//Escribimos los primeros 4 caracteres del mensaje
    return 0;
}
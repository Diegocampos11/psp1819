#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100], string2[100], string3[100];//Variables para almacenar las 3 cadaneas de texto
    fprintf( stdout, "Ingrese el primer mensaje:" );
    scanf( "%s", string );//Se almacena la primera cadena
    fprintf( stdout, "Ingrese el segundo mensaje:" );
    scanf( "%s", string2 );//Se almacena la segunda cadena
    fprintf( stdout, "Ingrese el tercer mensaje:" );
    scanf( "%s", string3 );//Se almacena la tercera cadena
    FILE* file = fopen( "./ejer2.txt", "w" );//Se abre el fichero para escribir en el
    fwrite( string, sizeof(char), 5, file );//Se escriben los primeros 5 caracteres de la primera cadena
    fputc( '\n', file );//salto de linea
    fwrite( string2, sizeof(char), 5, file );//Se escriben los primeros 5 caracteres de la segunda cadena
    fputc( '\n', file );
    fwrite( string3, sizeof(char), 5, file );//Se escriben los primeros 5 caracteres de la tercera cadena
    fputc( '\n', file );
    return 0;
}
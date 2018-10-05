#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[100], string2[100];//Variables para almacenar los mensajes
    fprintf( stdout, "Ingrese el primer mensaje:" );
    scanf( "%s", string );//Almacena el primer mensaje
    fprintf( stdout, "Ingrese el segundo mensaje:" );
    scanf( "%s", string2 );//Almacena el segundo mensaje
    FILE* file = fopen( "./ejer3.txt", "w" );//Se abre el fichero con permiso de escritura
    //printf( "%d %d", sl, s1l  );
    fwrite( string, sizeof(char), strlen( string ), file );//Se escribe toda la primera cadena con ayuda de strlen de la misma
    fputc('\n', file);//Salto de linea
    fputc('\n', file);
    fwrite( string2, sizeof(char), strlen( string2 ), file );//Se escribe toda la segunda cadena con ayuda de strlen de la misma
    return 0;
}
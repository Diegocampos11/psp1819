#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100], string2[100], string3[100];
    fprintf( stdout, "Ingrese el primer mensaje:" );
    scanf( "%s", string );
    fprintf( stdout, "Ingrese el segundo mensaje:" );
    scanf( "%s", string2 );
    fprintf( stdout, "Ingrese el tercer mensaje:" );
    scanf( "%s", string3 );
    FILE* file = fopen( "./ejer2.txt", "w" );
    fwrite( string, sizeof(char), 5, file );
    fputc( '\n', file );
    fwrite( string2, sizeof(char), 5, file );
    fputc( '\n', file );
    fwrite( string3, sizeof(char), 5, file );
    fputc( '\n', file );
    return 0;
}
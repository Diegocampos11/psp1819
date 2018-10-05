#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[100], string2[100];
    fprintf( stdout, "Ingrese el primer mensaje:" );
    scanf( "%s", string );
    fprintf( stdout, "Ingrese el segundo mensaje:" );
    scanf( "%s", string2 );
    FILE* file = fopen( "./ejer3.txt", "w" );
    //printf( "%d %d", sl, s1l  );
    fwrite( string, sizeof(char), strlen( string ), file );
    fputc('\n', file);
    fputc('\n', file);
    fwrite( string2, sizeof(char), strlen( string2 ), file );
    return 0;
}
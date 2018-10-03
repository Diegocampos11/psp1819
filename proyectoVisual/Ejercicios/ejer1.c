#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];
    fprintf( stdout, "Ingrese un mensaje:" );
    scanf( "%s", string );
    FILE* file = fopen( "./ejer1.txt", "w" );
    fwrite( string, 4, sizeof(char), file );
    return 0;
}
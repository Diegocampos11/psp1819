#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];
    fprintf( stdout, "Ingrese un mensaje:" );
    scanf( "%s", string );
    FILE* file = fopen( "./ejer1.txt", "w" );
    fwrite( string, sizeof(char), 4, file );
    return 0;
}
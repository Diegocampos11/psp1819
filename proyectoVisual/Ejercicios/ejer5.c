#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, i1;
    FILE* file = fopen( "./ejer4.dat", "r" );
    fread( &i, sizeof(int), 1, file );//Solo cuando se modifica la varialbe se pasa el &&&&
    fread( &i1, sizeof(int), 1, file );
    FILE* fileW = fopen( "./ejer5.txt", "w" );
    int suma = i + i1;
    printf( "%d", suma );
    fwrite( &suma, sizeof(int), 1, fileW );
    return 0;
}
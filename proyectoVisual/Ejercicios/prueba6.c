#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* fileW = fopen( "./ejer5.txt", "r" );
    int escrito;
    fread( &escrito, sizeof(int), 1, fileW );
    printf("La suma es : %d :D\n", escrito);
    return 0;
}
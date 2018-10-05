#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 5, i2 = 1;
    FILE* file = fopen( "./ejer4.dat", "wb" );
    fwrite( &i, sizeof(int), 1, file );
    fwrite( &i2, sizeof(int), 1, file );
    return 0;
}
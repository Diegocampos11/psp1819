#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];
    int i = 11, i2 = 1;
    FILE* file = fopen( "./ejer1.txt", "wb" );
    fwrite( &i, sizeof(int), 1, file );
    return 0;
}
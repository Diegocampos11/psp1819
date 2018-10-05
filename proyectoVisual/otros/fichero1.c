#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* file = fopen( "./hola.txt", "w" );
    char texto[]="Diego mundo";
    fwrite( texto, sizeof(char), 5, file);
    putc('\n', file);
    fseek( file, 0, SEEK_SET );
    fputc( 'J', file );
    fclose( file );
    return 0;
}

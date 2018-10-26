#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE* f = fopen( "./text.txt", "r" );
    if ( argv[1] == NULL ){//comprueba segundo parametro
        fprintf( stderr, "Debe de enviar el segundo parametro\n");
        return(-1);
    }
    printf( "%s\n", argv[1] );
    /*while( 1 ){
        char cLeido = fgetc( f );
        if( feof(f) ) break;
        
    }*/
    printf("Hecho!\n");
    fclose( f );
    return 0;
}

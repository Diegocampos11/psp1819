#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE* f = fopen( argv[1], "r" );
    if ( argv[2] == NULL ){//comprueba segundo parametro
        fprintf( stderr, "Debe de enviar el caracter a remover\n");
        return(-1);
    }
    if ( f == NULL ){
        fprintf( stderr, "Error: Fichero no encontrado\n");
        return(-1);
    }
    FILE* fw = fopen( "./textSinCaracter.txt", "w" );
    while( 1 ){
        char cLeido = fgetc( f );
        if( feof(f) ) break;
        if ( cLeido != argv[2][0] ) fputc( cLeido, fw);
    }
    printf("Hecho!\n");
    fclose( f );
    fclose( fw );
    return 0;
}

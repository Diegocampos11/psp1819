#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc, char const *argv[])
{
    FILE * fichero;
    fichero = fopen("./hola.txt", "r");
    if ( fichero == NULL ){
        //fprintf( stderr, "Error, no?" );
        perror("Error abriendo el fichero");
        fprintf( stderr, "File : "__FILE__" Error al abrir el fichero : %s : Line %d\n", strerror( errno ), __LINE__ );
        //En tiempo de compilación, en preprocesador
        //La mejor manera es imprimiendo strerror() usando la variable errno
    }
    return 0;
}

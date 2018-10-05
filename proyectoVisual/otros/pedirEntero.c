#include <stdio.h>

int main(int argc, char const *argv[])
{
    fprintf( stdout, "Ingrese su nombre:\n" );
    int nombre;
    fscanf( stdin, "%d", &nombre );//& DIRECCION DE MEMORIA DE LA VARIABLE NOMBRE... EN MODO ESCRITURA..?
    //%d define el tamaño de un entero, si coincide ambos tamaños (el tipo de tamaño leido y el de la variable) sirve :D
    fprintf( stdout, "El entero es %d y se encuentra en la dirección de memoria: %ld", nombre, &nombre );
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimirHolaMundo( /*tipo de dato como parametro*/ );

void imprimirASCIIhasta( char );

void imprimirHolaMundo(){
    fprintf( stdout, "Hola Mundo \n" );
}

int main(int argc, char const *argv[])
{
    char cad1[] = "Hola";
    char cad2[] = " ";
    char cad3[] = "Mundo.";

    //char cadRes[200] = "";//Inicializar la cadena a vacia
    int tamTotal = strlen( cad1 )+ strlen( cad2 ) + strlen(cad3)+1;//tamTotal total de las cadenas más barra 0
    char* cadRes = (char*) malloc( tamTotal * sizeof(char) );//ajustando al byte la memoria a usar, apunta a 12 bytes

    /*cadRes[0] =*/ cadRes = strcat( cadRes, cad1 );
    cadRes = strcat( cadRes, cad2 );
    cadRes = strcat( cadRes, cad3 );
    fprintf ( stdout, "%s\n", cadRes );
    free( cadRes );

    imprimirHolaMundo();

    imprimirASCIIhasta( 127 );
    return 0;
}

void imprimirASCIIhasta( char h ){
    
    for(int i = 1; i <= h; i++)
    {
        fprintf( stdout, "%d - %c\n", i, i );
    }
    
}
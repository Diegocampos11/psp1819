#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    /*if ( argv[1] != NULL ){
        int i = 1;
        while( i < argc ){
            printf("Hola %s\n", argv[i]);
            i++;
        }
    }*/
    int i = 1;
    while(true){
        printf( "Hola %s\n", argv[i] );
        if ( argv[++i] == NULL ) break;
    }
    
    return 0;
}
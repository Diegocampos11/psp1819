#include "libComun.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <regex.h>
//Comentario interesante xd
//%*[^\n] RECHAZA CUALQUIER CARACTER EXCEPTO EL BARRA N[^\n] HASTA ENCONTRAR UN BARRA N
//scanf("%c%*[^\n]%*c", &respuesta); //%*c rechaza cualquier caracter

bool getNum( char AB ){
    while( ! numValidado( AB ) );//infinito hata- obtener un numero valido
    
    if ( numDouble == 0 ){
        bool repetirRespuesta;//comprobar  que la respuesta sea 'S' o '\n'
        printf("¿Has ingresado 0?\nEscribe 'S' si quieres ingresar otro numero\nEn caso contrario presiona ENTER\n");
        while( preguntar() );//pido respuesta y aqui se valida que solo sea S o ENTER
        
        //paso a elegir en base a la respuesta :D
        if ( strcmp( respuesta, "S\n") == 0 ){
            return true;
        }
        else if ( strcmp( respuesta, "\n") == 0 ){
            return false;
        }
    }
    else return false;//el numero no es 0 y es valido!! :D
}

bool preguntar(){
    char* posError = fgets( respuesta, TAM_MAX, stdin );
    if ( posError == NULL ){//apunta a null
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar fgets\n", __LINE__ );
        return -1;
    }
    if ( strcmp( respuesta, "S\n") != 0 && strcmp( respuesta, "\n") != 0 ){
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: debes de escribir solamente 'S' y presionar ENTER si quieres ingresar otro número\nEn caso contrario solamente presiona ENTER para continuar\n", __LINE__);
        return true;
    }
    else return false;
}

bool numValidado( char AB ){
    regex_t regex;
    int resRegex;
    printf( "Ingresa el número %c:\nEjemplo: \"99.9999\",\"-99.9999\" ó \"99.9999\",\"-99.9999\"\n", AB);
    char* posError = fgets( numIngresado, TAM_MAX, stdin );
    if ( posError == NULL ){//apunta a null
        fprintf( stderr, "File : "__FILE__" : Line : %d : Error: no se pudo ejecutar fgets\n", __LINE__ );
        return -1;
    }
    resRegex = regcomp(&regex, "^(-)?([0-9]+)((,|.)([0-9]+))?\n$", REG_EXTENDED);
    if (resRegex) {
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: no pudo compilar regex\n", __LINE__);
        return false;
        //exit(1);
    }
    
    /* Execute regular expression */
    resRegex = regexec(&regex, numIngresado, 0, NULL, 0);
    if (!resRegex) {
        char i;//indice de '','' si la encuentra :D
        if ( ( i = strcspn( numIngresado, "," ) ) != -1 ) numIngresado[i] = '.';//si tiene "," reemplazarlo por ".""
        numDouble = atof( numIngresado );
        return true;
    }
    else if (resRegex == REG_NOMATCH) {
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: cifra ingresada inválida (Formato decimal americano o español)\n", __LINE__ );
        return false;
    }
    else {
        regerror(resRegex, &regex, numIngresado, sizeof(numIngresado) );
        fprintf(stderr, "File : "__FILE__" : Line : %d : Error: regex coincidencia fallida: %s\n", __LINE__, numIngresado);//se utiliza la misma variable para mostrar el error
        return false;
        //exit(1);
    }
    
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
}
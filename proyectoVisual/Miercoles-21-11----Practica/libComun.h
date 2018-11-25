#ifndef LIBCOMUN_H
#define LIBCOMUN_H
#include <stdbool.h>
#define TAM_MAX 50

char operacion[TAM_MAX];//almacenara el operador en ambos programas :D
//numIngresado sera utilizada en ambos programas para almacenar cualquier numero :D
char numIngresado[TAM_MAX];//para que la funciones no regresen un double, sean void. Asi mismo trabajo con una sola variable con ambos programas
//numDouble sera utilizado para validar un double desde cualquier programa... asi no tengo que pasar la direccion de memoria de funcion en funcion -> de getnum a numValido...
double numDouble;//Asi mismo no tendran que devolverla de funcion en funcion... y tengo un programa igual de estructurado con menos lineas de codigo.

char respuesta[TAM_MAX];//para no crearlas cada vez que se ejecuta el while al /***, asi mismo la funcion preguntar solo tendra que devolver true o false y no la respuesta**///

//metodos

bool getNum( char );//pide, valida, y convierte el numero a float

bool numValidado( char );//comprueba si el numero ha sido escrito correctamente

bool preguntar();//fuerza al usuario a ingresar solamente S

#endif
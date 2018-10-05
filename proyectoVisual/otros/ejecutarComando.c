#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if ( system("ls") == -1 ){
        fprintf(stderr, "Error ejecutando el comando\n");
    }
    fprintf(stdout, "\nAhora con execl\n");
    execl( "/bin/ls", "ls", "-a", (char*) NULL);//pathCompleta-nombre comando-paremtros del comando
    return 0;
}

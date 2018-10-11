#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    fprintf(stdout, "hola\n" );
    fflush( stdout );
    fork();
    fprintf(stdout, "xx\n");
    fprintf(stdout, "xx2\n");
    fflush( stdout );
    sleep(1);
    return 0;
}

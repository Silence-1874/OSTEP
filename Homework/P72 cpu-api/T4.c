#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I'm child\n");
        if( execl( "/bin/ls", "ls","-l", NULL ) == -1 ) {
            fprintf(stderr, "exec failed\n");
            exit(1);
        }
    } else {
        printf("I'm parent\n");
    }
    return 0;
}

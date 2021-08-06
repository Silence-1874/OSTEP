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
        close(STDOUT_FILENO);
        printf("I'm child(pid:%d)\n", (int) getpid());
    } else {
        printf("I'm parent(pid:%d)\n", (int) getpid());
    }
    return 0;
}

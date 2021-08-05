#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int wcc = wait(NULL);   //wcc = -1
        printf("I'm child(pid:%d), wcc = %d\n", (int) getpid(), wcc);
    } else {
        int wcp = wait(NULL);   //wcp = child process's pid
        printf("I'm parent(pid:%d), wcp = %d\n", (int) getpid(), wcp);
    }
    return 0;
}

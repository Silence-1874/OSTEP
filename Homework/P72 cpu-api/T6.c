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
        printf("I'm child(pid:%d)\n", (int) getpid());
    } else {
        int wcp = waitpid(-1, NULL, 0);   //wcp = child process's pid
        printf("I'm parent(pid:%d), wcp = %d\n", (int) getpid(), wcp);
    }
    return 0;
}

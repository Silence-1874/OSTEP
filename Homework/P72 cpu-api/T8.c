#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc_1 = fork();
    if (rc_1 < 0) {
        fprintf(stderr, "fork_1 failed\n");
        exit(1);
    } else if (rc_1 == 0) {
        close(fd[0]);
        char * str = "Hi! This is child_1\n";
        write(fd[1], str, strlen(str));
        printf("I'm child_1, my pid is %d\n", (int) getpid());
    }

    int rc_2 = fork();
    if (rc_2 < 0) {
        fprintf(stderr, "fork_2 failed\n");
        exit(1);
    } else if (rc_2 == 0) {
        sleep(1);
        close(fd[1]);
        char buf[1024];
        int len = read(fd[0], buf, 1024);
        if (len > 0) {
            buf[len] = '\0';
            printf("I'm child_2(pid:%d), this is from child_1-----%s", (int) getpid(), buf);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int f = open("./tmp.output", O_CREAT | O_RDWR, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        write(f, "c write\n\0", 9);
        printf("I'm child, f = %d\n", f);
    } else {
        write(f, "p write\n\0", 9);
        printf("I'm parent, f = %d\n", f);
    }
    return 0;
}

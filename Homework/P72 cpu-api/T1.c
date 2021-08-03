#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x += 100;
        printf("I'm child, my \"x\" is %d\n", x);   //x = 200
    } else {
        x -= 10;
        printf("I'm parent, my \"x\" is %d\n", x);  //x = 90
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    
    for (int i = 0; i < 10000000; i++) {
        write(0, "", 0);
    }

    gettimeofday(&end, NULL);
    
    long int ans = (end.tv_usec - start.tv_usec) / 1000;
    printf("The cost of system call 'write()' is %ld / 10000000 ms\n", ans);
    return 0;
}

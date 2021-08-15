#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define PAGESIZE 4096
#define NUMPAGES 1000

int main()
{
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    int jump = PAGESIZE / sizeof(int);
    int a[NUMPAGES * jump];
    for (int i = 0; i < NUMPAGES * jump; i += jump) {
        a[i] += 1;
    }

    gettimeofday(&end, NULL);

    long int ans = end.tv_usec - start.tv_usec;
    printf("The cost of time is %ld / %d us\n", ans, NUMPAGES);
}

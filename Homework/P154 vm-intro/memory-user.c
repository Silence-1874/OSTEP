#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    printf("Current pid = %d\n",getpid());
    long long int size = ((long long int)atoi(argv[1])) * 1024 * 1024; //in bytes
    int* buffer = (int*)malloc(size);

    time_t endwait, seconds, start;
    seconds = atoi(argv[2]);
    start = time(NULL);
    endwait = start + seconds;

    while (start < endwait) {
        //printf(".");
        //fflush(stdout);
        for(long long int i = 0; i < size / sizeof(int); i++){
            buffer[i] = i;
        }
        start = time(NULL);
    }
    printf("(done)\n");
    return 0;
}

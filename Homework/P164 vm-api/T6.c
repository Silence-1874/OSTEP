#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * data = (int *)malloc(100 * sizeof(int));
    free(data);
    for (int i = 0; i < 100; i++) {
        printf("%d\n", data[i]);
    }
    return 0;
}

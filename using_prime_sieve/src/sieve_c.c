#include <math.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

void sieve(char *a, int n)
{
    int i=0, j=0;
 
    for(i=2; i<=n; i++) {
        if(a[i] == 1) {
            for(j=i; (i*j)<=n; j++) {
                a[(i*j)] = 0;
            }
        }
    }
 
    // long cnt = 0;
    // for(i=2; i<=n; i++) {
    //     if(a[i] == 1)
    //         cnt++;
    // }
    // printf("count = %d" ,cnt);
}

int main(int argc, char *argv)
{   
    // struct timespec start, end;
    // clock_gettime(CLOCK_REALTIME, &start);
    double time_spent = 0.0;
    clock_t begin = clock();
    for(int i = 0; i<1000; ++i){
        char array[10001];
        memset(array, 1, 10000);
        sieve(array,10000);
    }
    clock_t end = clock();
    // clock_gettime(CLOCK_REALTIME, &end);
    // double time_spent = (end.tv_sec - start.tv_sec) +
    //                     (end.tv_nsec - start.tv_nsec);
    time_spent += (double)(end - begin);
    printf("Time elpased is %f s", (time_spent*10)/ CLOCKS_PER_SEC);

    return 0;
}
 
// 10000 times
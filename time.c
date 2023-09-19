#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <assert.h>
#define N 5



int main () {

    struct timeval start, end;


    int i, j, k;
    float matA[N][N], matB[N][N], matC[N][N], mult;

  
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            matA[i][j] = 10;
            matB[j][i] = 10;
        }
    }
    
    gettimeofday(&start, NULL);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            mult = 0;
            for(k = 0; k < N; k++) {
                mult += matA[i][k] * matB[k][j];
            }
            matC[i][j] = mult;
        }
    }

    gettimeofday(&end, NULL);

    double elapsed_time = (end.tv_sec - start.tv_sec)  + (end.tv_usec - start.tv_usec) * 1e-6;
    double gflops = (2.0 * N * N * N) / (elapsed_time * 1e9);

    int count = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            count++;
            printf("matriz %d c: %.2f \n",count, matC[i][j]);
        }
        printf("\n\n");
    }



    printf("o tempo da funcao test executar foi de: %.3f\n", elapsed_time);
    printf("a quantidade de gflops foi de: %.3f\n", gflops);


    return 0;
}
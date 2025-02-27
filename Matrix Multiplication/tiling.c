#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define N 8192

double A[N][N], B[N][N], C[N][N];
float tdiff(struct timeval *start, struct timeval *end){
    return (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_usec - start->tv_usec) / 1000.0;
}

int main() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            A[i][j] = (double)rand()/(double)RAND_MAX;
            B[i][j] = (double)rand()/(double)RAND_MAX;
            C[i][j] = 0;
        }
    }
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    int s = 64;
    #pragma omp parallel for
    for (int ih=0; ih<N; ih += s)
        for (int jh=0; jh<N; jh += s)
            for (int kh=0; kh<N; kh +=s)
                for (int il=0; il<s; il++)
                    for (int kl=0; kl<s; kl++) 
                        for (int jl=0; jl<s; jl++)
                            C[ih+il][jh+jl] += A[ih+il][kh+kl]*B[kh+kl][jh+jl];

    gettimeofday(&end, NULL);
    printf("%0.6f\n", tdiff(&start, &end));
    return 0;
}
#include <stdio.h>
#include <omp.h>
//Vladimir Ariel Lizarro Velasquez
void main() {
    int m, n;
    printf("Numero de vectores: ");
    scanf("%d", &m);
    printf("Numero de terminos: ");
    scanf("%d", &n);
    int v[m][n];
    #pragma omp parallel for num_threads(m)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j]=(i*n+j+1)*2;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d: ",i);
        for (int j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}
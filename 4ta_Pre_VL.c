#include <stdio.h>
#include <omp.h>
//Vladimir Ariel Lizarro Velasquez
void main(){
    int n, a, b;
    printf("Leer: \n");
    scanf("%d", &n);
    int M[n][n];
    int V[n];
    int R[n];
    printf("Llenado de la matriz.\n");
    for (int i = 0; i< n; i++) {
        for (int j = 0; j< n; j++) {
            scanf("%d", &a);
            M[i][j]=a;
        }
    }
    printf("Llenado del vector.\n");
    for (int i = 0; i< n; i++) {
        scanf("%d", &b);
        V[i]=b;
    }
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        R[i]=0;
        for (int j = 0; j < n; ++j) {
            R[i]+=M[i][j]*V[j];
        }
    }
    printf("Resultado.\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",R[i]);
    }
    printf("\n");
}

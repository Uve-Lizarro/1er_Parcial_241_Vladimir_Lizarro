#include <stdio.h>
#include <omp.h>
//Vladimir Ariel Lizarro Velasquez
void main() {
    int a, b;
    printf("Leer: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    int pro, aux;
    pro=0;
    #pragma omp parallel for reduction(+:pro)
    for (int i = 0; i < b; ++i) {
        pro+=a;
    }
    int co=0;
    while (a>=b) {
        #pragma omp parallel for reduction(-:a)
        for (int j = 0; j < b; ++j) {
            a-=b;
        }
        co++;
    }
    printf("Producto: %d\n",pro);
    printf("Division: %d\n",co);
}

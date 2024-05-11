#include <stdio.h>
#include <omp.h>
//Vladimir Ariel Lizarro Velasquez
void main() {
    int nroPro=omp_get_num_procs();
    #pragma omp parallel num_threads(nroPro)
    {
        int c=omp_get_thread_num();
        printf("Procesador %d: Hola Mundo\n", c);
    }
}

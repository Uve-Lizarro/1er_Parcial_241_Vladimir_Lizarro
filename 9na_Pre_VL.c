#include <stdio.h>
#include <mpi.h>
//Vladimir Ariel Lizarro Velasquez
void generaSerie(int i, int n, int *v) { 
    for (int j = 0; j < n; j++) { 
        int x=(i*n+j+1)*2; 
        v[j]=x; 
    } 
} 
void main(int argc, char** argv) { 
    int m;
    int n;
    int rango;
    int nroPro;
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rango); 
    MPI_Comm_size(MPI_COMM_WORLD, &nroPro); 
    if (rango==0) { 
        printf("Numero de vectores: "); 
        fflush(stdout); 
        scanf("%d", &m); 
        printf("Numero de terminos: "); 
        fflush(stdout); 
        scanf("%d", &n); 
    } 
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    int vR[n]; 
    MPI_Barrier(MPI_COMM_WORLD);
    for (int i = rango; i < m; i += nroPro) { 
        generaSerie(i,n,vR); 
        printf("%d: ", i); 
        for (int j = 0; j < n; j++) { 
            printf("%d ", vR[j]); 
        } 
        printf("\n"); 
    } 
    MPI_Finalize();
}

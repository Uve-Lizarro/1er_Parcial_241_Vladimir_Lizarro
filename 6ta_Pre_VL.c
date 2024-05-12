#include <stdio.h>  
#include <mpi.h>  
//Vladimir Ariel Lizarro Velasquez  
double metodo_Integral(int n, int rango, int nroPro) {  
    double s=0.0;  
    double b=1.0/n;
    int i; 
    int lim=n/nroPro;  
    int exc=n%nroPro;  
    int ini=rango*lim;
    int fin=(rango+1)*lim;
    if (rango==nroPro-1) {  
        fin+=exc;  
    }
    for (i = ini; i < fin; i++) {  
        double x=(i+0.5)*b;
        double fx=4.0/(1.0+(x*x));  
        s+=fx;
    }  
    double r;  
    MPI_Reduce(&s, &r, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    return r*b;
}
  
void main(int argc, char** argv) {  
    int n; 
    int rango; 
    int nroPro;  
    MPI_Init(&argc, &argv);  
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);  
    MPI_Comm_size(MPI_COMM_WORLD, &nroPro);
    if (rango==0) { 
        printf("Numero de iteraciones: "); 
        fflush(stdout);
        scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    double pi=metodo_Integral(n, rango, nroPro); 
    if (rango==0) {  
        printf("Valor de Pi: %.10f\n", pi);  
    }  
    MPI_Finalize();
}

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//Vladimir Ariel Lizarro Velasquez
#define TOTAL_POINTS 1000000

int main(int argc, char *argv[]) {
    int rank, size;
    double x, y, distance, pi;
    int points_inside_circle = 0;
    int total_points = TOTAL_POINTS;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Repartir el número total de puntos entre los procesos
    int points_per_process = total_points / size;
    int remaining_points = total_points % size;
    if (rank < remaining_points) {
        points_per_process++;
    }

    // Semilla diferente para cada proceso
    srand(rank);

    // Calcular los puntos y contar cuántos están dentro del círculo
    for (int i = 0; i < points_per_process; i++) {
        x = (double)rand() / RAND_MAX; // Coordenada X entre 0 y 1
        y = (double)rand() / RAND_MAX; // Coordenada Y entre 0 y 1
        distance = x * x + y * y;
        if (distance <= 1.0) {
            points_inside_circle++;
        }
    }

    // Sumar los puntos dentro del círculo de todos los procesos
    int total_inside_circle;
    MPI_Reduce(&points_inside_circle, &total_inside_circle, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calcular el valor aproximado de Pi en el proceso 0
    if (rank == 0) {
        pi = (double)total_inside_circle / total_points * 4;
        printf("Valor aproximado de Pi: %f\n", pi);
    }

    MPI_Finalize();

    return 0;
}

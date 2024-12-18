#include <iostream>
#include <mpi.h>
#include <vector>

int main(int argc, char *argv[]) {
    // Verificación de argumentos de entrada
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " --n [vector_size]" << std::endl;
        return 1; // Usar return en lugar de exit para consistencia
    }

    // Lectura del tamaño del vector desde la línea de argumentos
    int n = atoi(argv[2]);
    if (n <= 0) {
        std::cerr << "Error: el tamaño del vector debe ser un número positivo." << std::endl;
        return 1;
    }

    
    // Inicialización de MPI
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Número de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Rango del proceso actual

    double time_start = MPI_Wtime(); // Tiempo inicial

    // División del trabajo entre procesos
    int nlocal = n / size; // Tamaño base para cada proceso
    int rest = n % size;   // Elementos sobrantes a distribuir

    if (rest && (rank < rest))  // Si existe elementos sobrantes, los primeros procesos reciben un elemento extra
        nlocal++;
    
    int start = rank * nlocal; // Definimos un punto de comienzo 
    if (rest && (rank >= rest)) // los rangos menores son los que recibieron un trozo mas grande
        start += rest;

    int end = start + nlocal; // Ahora definimos un punto final

    // Inicialización de los vectores locales x e y
    std::vector<double> x(nlocal, 1.0); // Vector x inicializado con 1.0
    std::vector<double> y(nlocal, -1.0); // Vector y inicializado con -1.0
    double alpha = 2.5; // Escalar para la operación AXPY
    
    // Computación de AXPY local (y = y + alpha * x)
    for (int i = 0; i < nlocal; ++i) {
        y[i] += alpha * x[i];
    }

    // Imprimir los resultados locales desde cada proceso
    //std::cout << "Proceso " << rank << ". Vector y local: y = [";
    //for (int i = 0; i < nlocal; ++i) {
        //std::cout << y[i];
        //if (i < nlocal - 1) std::cout << ", "; // Evitar la coma final
    //}
    //std::cout << "]" << std::endl;

    double time_end = MPI_Wtime(); // Tiempo final


    // El proceso maestro imprime el tiempo total
    if (rank == 0) {
        std::cout << "Tiempo total (s): " << time_end - time_start << std::endl;
    }

    // Finalización de MPI
    MPI_Finalize();
    return 0;
}



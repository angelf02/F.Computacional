#include <iostream>
#include <complex>
#include <vector>
#include <omp.h>
#include <sys/time.h>

// Función para determinar el tiempo de cálculo
double seconds(){
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  
  return sec;
}

// Función para determinar si un número c está fuera o dentro del conjunto
// de Maldenbrot con la cantidad de iteraciones máximas
int mandelbrot(const std::complex<double> &c, const int &maxits){
  std::complex<double> z = 0;
  int n = 0;
  while(abs(z) <= 2 && n < maxits){
    z = z * z + c;
    ++n;
  }
    
  return n;
}

// Función para imprimir la matriz
void print_mat(const std::vector<char> &mat, int &rows, int &cols){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << mat[(i * cols) + j];
    }
    std::cout << std::endl;
  }
}

int main(){
    // Ancho y alto de la salida del programa
    int width = 155; // 3840
    int height = 50; // 2160
    // Número máximo de iteraciones (corte)
    int max_iter = 1000;
    // Coordenadas en el plano complejo máximas y mínimas
    double minX = -2.0, maxX = 1.0;
    double minY = -1.0, maxY = 1.0;

    // Vector de resultados
    std::vector<char> resultado(width*height, '.');


    int num_procs;

    // Rutina principal para generar e imprimir el conjunto
    double time_1 = seconds();
    // Paralelización del algoritmo con base en una subdivision de las filas:
    //#pragma omp parallel 
    //{
      //num_procs = omp_get_num_threads();
      //#pragma omp for
      for(int y = 0; y < height; ++y){
        // Paralelización del algoritmo con base en una subdivision de las columnas:
        //#pragma omp parallel
        //{
          //num_procs = omp_get_num_threads();
          //#pragma omp for 
            for(int x = 0; x < width; ++x){
              // Mapeo de pixeles a número complejo
              std::complex<double> c( minX + (maxX - minX) * x / width,
                                      minY + (maxY - minY) * y / height );
            
              // Cálculo del número de iteraciones
              int n = mandelbrot(c, max_iter);
  
              // Se guarda un caracter dependiendo del número de iteraciones
              if(n == max_iter){
                  resultado[(y * width) + x] = '#'; // Dentro del conjunto de Mandelbrot
              } 
            }
        //}
      }
    //}
    double time_2 = seconds();
    
    // Imprimir el resultado
    print_mat(resultado, height, width);

    std::cout << "# Num Threads: " << num_procs << std::endl;
    std::cout << "# Time: " << time_2 - time_1 << std::endl;
    return 0;
}

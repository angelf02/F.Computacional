#include <iostream>
#include <complex>

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

int main(){

  // Ancho y alto de la salida del programa
  int width = 150;
  int height = 45;
  // Número máximo de iteraciones (corte)
  int max_iter = 1000;
  // Coordenadas en el plano complejo máximas y mínimas
  double minX = -2.0, maxX = 1.0;
  double minY = -1.0, maxY = 1.0;

  // Rutina principal para generar e imprimir el conjunto
  for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x){
      // Mapeo de pixeles a número complejo
      std::complex<double> c( minX + (maxX - minX) * x / width,
                              minY + (maxY - minY) * y / height );

      // Cálculo del número de iteraciones
      int n = mandelbrot(c, max_iter);

      // Se imprime un caracter dependiendo del número de iteraciones
      if(n == max_iter){
        std::cout << '#'; // Dentro del conjunto de Mandelbrot
      } 
      else{
        std::cout << '.'; // Fuera del conjunto de Mandelbrot
      }
    }
    std::cout << std::endl; // Siguiente línea en y
  }

  return 0;
}

#include <iostream>

//Primero se define el integrando:
double funcionpi(double x){
  return 4.0 / (1.0 + x*x);
}

//Luego, dentro del main inicializo "div" para luego guardar el input del usuario ahi.
//Defino las demas variables necesarias (limite inferior, limite superior, el resultado de la sumatoria, y el ancho de la divisiones).
//Uso un for para iterar el calculo para cada rectangulo. Voy sumando las areas, que corresponde a ancho por altura (funcion evaluada en el punto medio de las divisiones).
int main(){
  int div;
  std::cout << "Ingrese el numero de particiones: " << std::endl;
  std::cin >> div;

  double l_inf = 0.0;  
  double l_sup = 1.0;
  double suma = 0.0;
  double ancho = (l_sup-l_inf)/div;
  
  for (int n = 0; n < div + 1; n++){
    suma += funcionpi(l_inf+((ancho*n)-(ancho/2)))*ancho;
  }
  
  //Se imprime el resultado.
  std::cout.precision(10);
  std::cout << "Aproximacion de pi: " << suma << std::endl;

  return 0;
}


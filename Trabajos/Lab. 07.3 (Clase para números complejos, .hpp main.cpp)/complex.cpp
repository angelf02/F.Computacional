#include <iostream>
#include <cmath>
#include "complex.hpp"

//Constructor por defecto
Complex::Complex(){
  real = 0;
  imag = 0;
}

//Constructor
Complex::Complex(float a, float b){
  real = a;
  imag = b;
}

//Constructor copia
Complex::Complex(const Complex &obj){
  real = obj.real;
  imag = obj.imag;
}

// Operador asignación
Complex &Complex::operator=(const Complex &obj){
  real = obj.real;
  imag = obj.imag;
  return *this;
}

//Destructor
Complex::~Complex(){
}

//Norma
double Complex::norma(){
  return sqrt(real*real+imag*imag);
}

//Conjugado (funcion miembro)
void Complex::conjugado(){
  imag = -1.0*imag;
}

//Operador +
Complex Complex::operator+(const Complex &obj){
  Complex temp;
  temp.real =  real + obj.real;
  temp.imag =  imag + obj.imag;
  return temp;
}

//Operador -
Complex Complex::operator-(const Complex &obj){
  Complex temp;
  temp.real =  real - obj.real;
  temp.imag =  imag - obj.imag;
  return temp;
}

//Operador *
Complex Complex::operator*(const Complex &obj){
  Complex temp;
  temp.real =  real*obj.real - imag*obj.imag;
  temp.imag =  real*obj.imag + imag*obj.real;
  return temp;
}

//Operador /
Complex Complex::operator/(const Complex &obj){
  Complex temp;
  temp.real = (real*obj.real + imag*obj.imag) / (obj.real*obj.real + obj.imag*obj.imag);
  temp.imag =  (imag*obj.real - real*obj.imag) / (obj.real*obj.real + obj.imag*obj.imag);
  return temp;
}

//Impresion
void Complex::print(){
        std::cout << real << " + " << imag << "i" << std::endl;
}


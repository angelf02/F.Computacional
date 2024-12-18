#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
  public:
    double real;
    double imag;
    Complex(); //Contructor por defecto
    Complex(float a, float b); //Constructor
    Complex(const Complex &obj); //Constructor copia
    Complex &operator=(const Complex &obj); //Operador asignacion
    ~Complex(); //Destructor
    double norma();
    void conjugado();
    Complex operator+(const Complex &obj);
    Complex operator-(const Complex &obj);
    Complex operator*(const Complex &obj);
    Complex operator/(const Complex &obj);
    void print();
};
#endif

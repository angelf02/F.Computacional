#include <iostream>
#include "complex.hpp"

int main(){
        Complex a(2,-3);
        Complex b(4,5);
        std::cout << "a = ";
        a.print();
        std::cout << "b = ";
        b.print();

        Complex c = a;
        std::cout << "c = a = ";
        c.print();

        std::cout << "La norma de a es: " << a.norma() << std::endl;

        c.conjugado();
        std::cout << "c conjugado: ";
        c.print();

        Complex d = a+b;
        std::cout << "d = a+b = ";
        d.print();

        Complex e = a-b;
        std::cout << "e = a-b = ";
        e.print();

        Complex f = a*b;
        std::cout << "f = a*b = ";
        f.print();

        Complex g = a/b;
        std::cout << "g = a/b = ";
        g.print();

        return 0;
}


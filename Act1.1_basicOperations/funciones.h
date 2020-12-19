//
//  Act1.1.h
//  
//  ITESM QRO.
//  Israel Ivan Arroyo Parada
//  A01706190

#ifndef Act1_1_h
#define Act1_1_h
#include <iostream>

using namespace std;
class Funciones
{
public:
    int sumaIterativa(int n);
    int sumaRecursiva(int n);
    int sumaDirecta(int n);
};

int Funciones::sumaIterativa(int n)
{
//    Suma iterativa de 1 hasta N
//    Recibe un int n positivo
//    regresa int positivo
    int acum = 0;
    for (int i = 1; i <= n;i++)
    {
        acum = acum + i;
    }
    return acum;
}
int Funciones::sumaRecursiva(int n)
{
//    Suma recusiva de 1 hasta N
//    Recibe un int n positivo
//    regresa int positivo
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n + sumaRecursiva(n-1);
    }
}
int Funciones::sumaDirecta(int n)
{
//    Suma directa, usando formula de sumatorias, de 1 hasta N
//    recibe un int n positivo
//    regresa int positivo
    int acum=(n*(n+1))/2;
    return acum;
}

#endif /* Act1_1_h */

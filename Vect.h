#ifndef VECT_H
#define VECT_H
#include <math.h>

#include "Fraccion.h"

class Vect{
protected: 
    Fraccion *vec;
    int size;
    int sizeMem;
    void setSize(int);
    
public:
    Vect();
    Vect(int);
    Vect(int, Fraccion *);
    
    int getSize();

    Vect operator + (Vect);
    Vect operator - (Vect);
    float operator * (Vect);

    Vect suma(Vect inaArrfrac);
    void sumaInPlace(Vect inaArrfrac);
    Vect resta(Vect inaArrfrac);
    Vect multiplicacion(Vect inaArrfrac);
    float multiPunto(Vect inaArrfrac);

    Fraccion getFraccion(int);

    void setFraccion(int, Fraccion);
    void agregarFraccion(Fraccion);
    void eliminarFraccion();

    Vect producto(Vect);

    float angulo(Vect);
    float magnitud();
    Vect producto(int);
    Vect producto(float);

    void print();
};

#endif //VECT_H
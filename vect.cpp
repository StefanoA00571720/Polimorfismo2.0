#include "Vect.h"
#include <iostream>

#include <string>
#include <cmath>
#include <math.h>

using namespace std;

//Constructor sin argumentos
Vect::Vect(){
    vec = new Fraccion[1];
    size = 1;
    sizeMem = 1;
}

//Constructor con tamaño especifico
Vect::Vect(int s){
    size = s;
    vec = new Fraccion[s];
    sizeMem = s;
}

//Constructor con arreglo especifico
Vect::Vect(int s, Fraccion * arrf){
    vec = arrf;
    size = s;
    sizeMem = s;
}

//Obtener tamaño del arreglo
int Vect::getSize(){
    return size;
}

//Definir tamaño del arreglo
void Vect::setSize(int siz){
  size=siz;
}

//Obtener Fraccion por indice
Fraccion Vect::getFraccion(int i){
    return vec[i];
}

//Cambiar una fraccion por indice
void Vect::setFraccion(int i, Fraccion f){
    vec[i] = f;
}

//Suma de fracciones (no modifica el objeto actual)
Vect Vect::suma(Vect inaArrfrac){ 
    // Si los tamaños de los arreglos coinciden
    if(size == inaArrfrac.getSize()){
        Vect newArrfrac(size);
        for (int i=0; i<size; i++){
            //En la nueva fraccion establece el resultado de la suma entre las 2 fracciones con el mismo indice
            newArrfrac.setFraccion(i, vec[i].suma(inaArrfrac.getFraccion(i)));  
        }
        return newArrfrac;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

//Resta de fracciones (no modifica el objeto actual)
Vect Vect::resta(Vect inaArrfrac){
      if(size == inaArrfrac.getSize()){
        Vect newArrfrac(size);
        for (int i=0; i<size; i++){
            //En la nueva fraccion establece el resultado de la suma entre las 2 fracciones con el mismo indice
            newArrfrac.setFraccion(i, vec[i].resta(inaArrfrac.getFraccion(i)));  
        }
        return newArrfrac;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

//Multiplicacion de fracciones (no modifica el objeto actual)
Vect Vect::multiplicacion(Vect inArrfrac){ 
    // Si los tamaños de los arreglos coinciden
    if(size == inArrfrac.getSize()){
        Vect newArrfrac(size);
        for (int i=0; i<size; i++){
            //En la nueva fraccion estable el resultado de la multiplicacion entre las 2 fracciones con el mismo indice
            newArrfrac.setFraccion(i, vec[i].multiplicacion(inArrfrac.getFraccion(i)));  
        }
        return newArrfrac;
        //---
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

float Vect::multiPunto(Vect vec){
  if (size == vec.size){
      Fraccion *frac = vec.vec;
      Fraccion *mult = new Fraccion[size];

      for (int i = 0; i< size; i++){
          mult[i] = this->vec[i] * frac[i];
      }
      
      Fraccion suma(0,0);

      for (int i = 0; i< size; i++){
          suma = suma + mult[i];
      }
      
      delete[] mult;

      float res=suma.aFloat(); //NUEVO
      
      return res;
  } else {
    cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
    return 0; 
  }

}

//Suma de fracciones (si modifica el objeto actual) [como ejemplo alternativo de la funcion suma]
void Vect::sumaInPlace(Vect inaArrfrac){
    // Si los tamaños de los arreglos coinciden
    if(size == inaArrfrac.getSize()){
        for (int i=0; i<size; i++){
            //Realiza la suma y la guarda en el objeto que llama este metodo
            vec[i] = vec[i].suma(inaArrfrac.getFraccion(i));  
        }
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
    }
}   

void Vect::agregarFraccion(Fraccion f){
    // Se duplica el tamaño de la memoria para evitar trasladar arreglos de elementos cada que se agrega una fraccion
    if(size+1 > sizeMem){
        //Se crea un nuevo arreglo de fracciones con el doble de memoria
        Fraccion * newArr = new Fraccion[size*2];
        //Se copia el arreglo en el nuevo arreglo
        for (int i=0;  i<size; i++){
            newArr[i] = vec[i];
        }
        newArr[size+1] = f;
        vec = newArr;
        sizeMem = size*2;
        size = size+1;
    }else{
        //Si hay suficiente memoria reservado, entonces, simplemente agregalo
        vec[size+1] = f;
        size++;
    }
}

void Vect::eliminarFraccion(){ //ultimo elemento
    vec[size].setNumerador(0);
    vec[size].setDenominador(1);
    size--;
} 

Vect Vect::producto(Vect vector){
  Fraccion *vecF = vector.vec; 
  if (size==3 && vector.size == 3){
 
    Fraccion a1=vec[0];
    Fraccion a2=vec[1];
    Fraccion a3=vec[2];
    Fraccion b1=vecF[0];
    Fraccion b2=vecF[1];
    Fraccion b3=vecF[2];

    Fraccion f1=(a2*b3)-(a3*b2);
    Fraccion f2=(a3*b1)-(a1*b3);
    Fraccion f3=(a1*b2)-(a2*b1);

    Fraccion *p= new Fraccion[3];

    p[0]=f1;
    p[1]=f2;
    p[2]=f3;

    Vect Res(3,p);

    return Res;

  } else {
    cout<<"La dimension de alguno de los vectores es diferente a 3"<<endl;
    Vect vecAlternativo;
    return vecAlternativo;
  }
}

//Imprimir info de vectores

void Vect::print(){
    bool showSize=false;
    if(showSize)
        cout << "size: " << size << ", sizeMem: " << sizeMem << " --- "; 
    cout << "[";
    int i;
    for (i=0; i<size; i++){
        cout << vec[i].getNumerador() << "/" << vec[i].getDenominador();
        if( i < size-1)
            cout << ", ";
    }
    cout << "]" << endl;    
} 

//SOBRE CARGA DE OPERADORES  ///////////////////////////////////////

Vect  Vect::operator + (Vect v){
  return this->suma(v);
}


Vect Vect::operator - (Vect v){
  return this->resta(v);
}

//producto punto, no multiplicación 
float Vect::operator * (Vect v){
  return this->multiPunto(v);
}

//producto, vect[fraccion]*fraccion /////////////////////////////////

Vect Vect::producto(int num){
  Fraccion f1(num,1);

  Fraccion *p=new Fraccion[size];

  for (int i=0; i<size; i++){
    p[i]=vec[i]*f1;
  }

  Vect res(size,p);

  return res;
}

Vect Vect::producto(float num){
  Fraccion f1(lround(num),1);

  Fraccion *p=new Fraccion[size];

  for (int i=0; i<size; i++){
    p[i]=vec[i]*f1;
  }

  Vect res(size,p);

  return res;
}

//Magnitud ///////////////////////
float Vect::magnitud(){
  Fraccion *p=new Fraccion[size];

  for (int i=0; i<size; i++){
    p[i]=vec[i]*vec[i];
  }

  Vect res1(size,p);

  Fraccion *q=new Fraccion[size];

  Fraccion ad(1,1);

  for (int i=0; i<size; i++){
    q[i]=ad;
  }

  Vect res2(size,q);

  float magnitudSinRaiz=res1*res2;

  float magnitud=sqrt(float(magnitudSinRaiz));

  return magnitud;

}

//Angulo entre vectores
float Vect::angulo(Vect vB){

  if(size == vB.size){
    Vect vA(size,vec);

    float magnitudA=magnitud();
    float magnitudB=vB.magnitud();
    float productoPuntoAB=vA*vB;

    float adentro=((float(productoPuntoAB))/(float(magnitudA)*float(magnitudB)));
    //cout<<"adentro:"<<adentro<<endl;
    float angulo=acos(float (adentro));
    float anguloRes = (float(angulo))*(180.0000000000000/3.141592); 
    return anguloRes;
  } else {
    cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
    return 0; 
  }
 
}
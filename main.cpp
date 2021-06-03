#include <iostream>
#include <string>

#include <cmath>

#include <math.h>

#include "Fraccion.h"
#include "Vect.h"

using namespace std;

int main(){
  
  // PRUEBA VECTORES DE CUATRO DIMENSIONES 

  // DEFINICIÓN DE VECTORES

  // Componentes vector 1 
  Fraccion f1(1,2); 
  Fraccion f2(3,4); 
  Fraccion f3(1,1); 
  Fraccion f4(4,5); 

  // Componentes vector 2 
  Fraccion f5(3,2); 
  Fraccion f6(1,2); 
  Fraccion f7 = f1 + f2; 
  Fraccion f8 = f3 * f4; 

  Fraccion fv1[4] = {f1,f2,f3,f4}; 
  Fraccion fv2[4] = {f5,f6,f7,f8}; 

  Fraccion *fv1p = fv1; 
  Fraccion *fv2p = fv2; 

  Vect vec1(4,fv1p);
  Vect vec2(4,fv2p); 

  // OPERACIONES 
  cout<<"\nPRUEBAS\n---- Vectores de 4 dimensiones ----"<<endl; 
  cout<<"Vector 1"<<endl; 
  vec1.print();  
  cout<<"\nVector 2"<<endl; 
  vec2.print(); 

  // Suma 
  cout<<"\nSuma\n"; 
  Vect suma1 = vec1 + vec2; 
  suma1.print(); 

  // Resta 
  cout<<"\nResta\n"; 
  Vect resta1 = vec1 - vec2; 
  resta1.print(); 

  // Producto punto 
  cout<<"\nProducto Punto\n"; 
  float punto1 = vec1 * vec2; 
  cout<<punto1<<endl; 

  // Producto cruz 
  cout<<"\nProducto Cruz\n"; 
  Vect producto1 = vec1.producto(vec2); 
  producto1.print(); 

  // Ángulo entre vectores 
  cout<<"\nÁngulo entre vectores\n"; 
  float ang1 = vec1.angulo(vec2); 
  cout<<ang1<<endl; 

  // Magnitud de vector 
  cout<<"\nMagnitud del vector 1\n"; 
  float mag1 = vec1.magnitud(); 
  cout<<mag1<<endl; 

  // Escalamiento 
  cout<<"\nEscalamiento vector 1 (por 2)\n"; 
  Vect escala1 = vec1.producto(2); 
  escala1.print(); 

  cout<<"\nEscalamiento vector 1 (por 2.0)\n"; 
  Vect escala11 = vec1.producto(float(2.0)); 
  escala11.print(); 

  cout<<"\nEscalamiento vector 1 (por 2.1) [Finalmente, multiplica por 2]\n"; 
  Vect escala111 = vec1.producto(float(2.1)); 
  escala111.print();

  // PRUEBA VECTORES DE TRES DIMENSIONES 

  // DEFINICIÓN DE VECTORES
  Fraccion fv1_[3] = {f1,f2,f3}; 
  Fraccion fv2_[3] = {f4,f5,f6}; 

  Fraccion *fv1p_ = fv1_; 
  Fraccion *fv2p_ = fv2_; 

  Vect vec1_(3,fv1p_); 
  Vect vec2_(3,fv2p_); 

  // OPERACIONES 
  cout<<"\n---- Vectores de 3 dimensiones ----"<<endl; 
  cout<<"Vector 1"<<endl; 
  vec1_.print();  
  cout<<"\nVector 2"<<endl; 
  vec2_.print(); 

  // Suma 
  cout<<"\nSuma\n"; 
  Vect suma2 = vec1_ + vec2_; 
  suma2.print(); 

  // Resta 
  cout<<"\nResta\n"; 
  Vect resta2 = vec1_ - vec2_; 
  resta2.print(); 

  // Producto punto 
  cout<<"\nProducto Punto\n"; 
  float punto2 = vec1_ * vec2_; 
  cout<<punto2<<endl; 

  // Producto cruz 
  cout<<"\nProducto Cruz\n"; 
  Vect producto2 = vec1_.producto(vec2_); 
  producto2.print(); 

  // Ángulo entre vectores 
  cout<<"\nÁngulo entre vectores\n"; 
  float ang2 = vec1_.angulo(vec2_); 
  cout<<ang2<<endl; 

  // Magnitud de vector 
  cout<<"\nMagnitud del vector 2\n"; 
  float mag2 = vec2_.magnitud(); 
  cout<<mag2<<endl; 

  // Escalamiento 
  cout<<"\nEscalamiento vector 2 (por 3)\n"; 
  Vect escala2 = vec2_.producto(3); 
  escala2.print(); 

  cout<<"\nEscalamiento vector 2 (por 3.0)\n"; 
  Vect escala22 = vec2_.producto(float(3.0)); 
  escala22.print(); 

  cout<<"\nEscalamiento vector 2 (por 3.1) [Finalmente, multiplica por 3]\n"; 
  Vect escala222 = vec2_.producto(float(3.1)); 
  escala222.print(); 

  // PRUEBA VECTORES CON DIMENSIONES DIFERENTES

  // OPERACIONES 
  cout<<"\n---- Vectores con dimensiones diferentes ----"<<endl; 
  cout<<"Vector 1 (4)"<<endl; 
  vec1.print();  
  cout<<"\nVector 2 (3)"<<endl; 
  vec1_.print(); 

  // Suma 
  cout<<"\nSuma\n"; 
  Vect sumaD = vec1_ + vec1; 
  sumaD.print(); 

  // Resta 
  cout<<"\nResta\n"; 
  Vect restaD = vec1_ - vec1; 
  restaD.print(); 

  // Producto punto 
  cout<<"\nProducto Punto\n"; 
  float puntoD = vec1_ * vec1; 
  cout<<puntoD<<endl; 
 
  // Producto cruz 
  cout<<"\nProducto Cruz\n"; 
  Vect productoD = vec1_.producto(vec1); 
  productoD.print(); 

  // Ángulo entre vectores 
  cout<<"\nÁngulo entre vectores\n"; 
  float angD = vec1_.angulo(vec1); 
  cout<<angD; 

}
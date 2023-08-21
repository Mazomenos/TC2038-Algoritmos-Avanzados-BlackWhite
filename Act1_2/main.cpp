/*
Equipo:  

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038 

Fecha 19 de Agosto del 2023


*/

#include <iostream>



//using namespace std;

void greedy(int monedas[], int cambio, int n){
  int temp;
  for (int i =0; i<n; i++){

    if (monedas[i]>cambio){
      std::cout << monedas[i] << " ";
      monedas[i] = 0;
      std::cout << monedas[i] << std::endl;
    } 
    
    else{
    std::cout << monedas[i] << " ";
    temp = cambio/monedas[i];
    cambio = cambio % monedas[i];
    monedas[i] = temp;
    std::cout << monedas[i] << std::endl;
    }
  }

}


int main() {
  int n, p, q, cambio;
  

  std::cin>>n;

  int monedas[n];

  for(int i=0; i<n; i++){
    std::cin>>monedas[i];
  }

  std::cout << "money" << std::endl;

  std::cin>>p>>q;

  

  if(p<q){
    cambio = q-p;

    std::cout << "cambio: " << cambio << std::endl; 

    greedy(monedas, cambio, n);


  } else{
    std::cout<<"Precio es mayor que el pago"<<std::endl;
    return 0;
  }
}

/*
Equipo:  

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038 

Fecha 19 de Agosto del 2023


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>


//using namespace std;

void dynamic(int monedas[], int cambio, int n) {

  std::vector<int> lista(n,0);
  std::vector<int> minMonedas(cambio + 1, INT_MAX);
  std::vector<std::vector<int>> combinaciones(cambio + 1);

  minMonedas[0] = 0;
  combinaciones[0].push_back(0); 

  for (int i = 1; i<=cambio; i++){
    
    for (int j = 0; j<n; j++){
      if (i>=monedas[j] && minMonedas[i - monedas[j]]+1 < minMonedas[i]){
        
        minMonedas[i] = minMonedas[i-monedas[j]] + 1;
        
        combinaciones[i] = combinaciones[i-monedas[j]];
        
        combinaciones[i].push_back(monedas[j]);
       
      }
    }
    
  }  
  std::cout << "Dinamic" << std::endl; 
  for (int k = 1; k<=minMonedas[cambio]; k++){
    for (int l = 0; l<n ; l++){
      if (combinaciones[cambio][k] == monedas[l]){
        lista[l] += 1;
      }
    }
    //std::cout << combinaciones[cambio][k] << std::endl;
  }

  for (int m = n-1; m>=0; m--){
    std::cout << monedas[m] << " " << lista[m] << std::endl;
  } 

}


void greedy(int monedas[], int cambio, int n){
  int temp;
  for (int i = 0; i<n; i++){

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
  int n, valor, p, q, cambio;
  

  std::cin>>n;

  int monedasUp[n];
  int monedasDown[n];

  for(int i=0; i<n; i++){
    std::cin>>valor;
    monedasUp[i] = valor;
    monedasDown[i] = valor;

  }

  std::cout << "money" << std::endl;

  std::cin>>p>>q;

  

  if(p<q){
    cambio = q-p;

    std::cout << "cambio: " << cambio << std::endl; 

    std::sort(monedasUp, monedasUp + n);
    std::sort(monedasDown, monedasDown + n, std::greater<int>());



    greedy(monedasDown, cambio, n);
    dynamic(monedasUp, cambio, n);


  } else{
    std::cout<<"Precio es mayor que el pago"<<std::endl;
    return 0;
  }
}

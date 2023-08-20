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

using namespace std;

int main() {
  int numDiv, precio, pago, cambio;

  cin>>numDiv;

  vector<int> divisas(numDiv);

  for(int i=0; i<numDiv; i++){
    cin>>divisas[i];
    cout<<divisas[i]<<endl;
  }

  cin>>precio>>pago;

  if(precio<pago){
    cambio = pago-precio;
  } else{
    cout<<"Precio es mayor que el pago"<<endl;
  }
}

/*
Equipo:  

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro (Noogler)

TC2038 

Fecha 10 de Agosto del 2023


*/

#include <iostream>

using namespace std;



int main() {
    //Se declaran las variables del contador y de n (size)
    int i,n;
    //Ingresar n (size)
    cin >> n;
    int list[n];
    for (i = 0; i < n; i++) {
        cin >> list[i];
    }
    //Print de Valores
    cout << "Lista de Valores: " << endl;
    for (i = 0; i < n; i++) {
        cout << list[i] << endl;
    }

    //return main
    return 0;
}
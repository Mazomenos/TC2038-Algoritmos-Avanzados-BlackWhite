/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 3 de Septiembre del 2023

Compilacion para ejecucion:
 g++ -std=c++17 -O3 -o main *.cpp
Ejecucion:
 ./main < test01.txt

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(){
    int N,M;
    string prefijo;

    cin >> N;

    string arrPalabrasA[N];

    for (int i = 0; i < N; i++){
        cin >> arrPalabrasA[i];

    }

    cin >> M;

    string arrPalabrasB[M];

    for (int i = 0; i < M; i++){
        cin >> arrPalabrasB[i];

    }

    cin >> prefijo;








    return 0;
}

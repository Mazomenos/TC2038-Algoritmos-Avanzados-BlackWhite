/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 22 de Septiembre del 2023

Compilacion para ejecucion:
 g++ -std=c++17 -O3 -o main *.cpp
Ejecucion:
 ./main < test01.txt

* Ejemplo que implementa un Trie (Arbol de prefijos)
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp
*   
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < TestCases/test01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
*    g++ main.cpp nodeTrie.cpp trie.cpp 
* Ejecucion:
*    ./main < TestCases/test01.txt
**/
#include <iostream>
#include "trie.h"

using namespace std;

//This code has a time complexity of O(N)
//TIme complexities for each individual function are in the trie.cpp file
int main() {
  trie T;
  int N = 0;
  int M = 0;
  string palabra, prefix = "";

  // Insertar N palabras
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> palabra;
    T.insert(palabra);
  }  
  // Recorrido DFS
  T.dfs(nullptr, "");
  // Buscar M palabras
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> palabra;
    cout << boolalpha << T.search(palabra) << endl;
  }
  cin >> prefix;
  T.autoComplete(prefix);
  

  // AutoComplete
  return 0;
}
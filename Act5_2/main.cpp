/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 6 de Noviembre del 2023

Compilacion para ejecucion:
 g++ -std=c++17 -O3 -o main *.cpp
Ejecucion:
 ./main < TestCases/test01.txt

*/

#include "Graphs.h"
#include <iostream>
#include <sstream>


using namespace std;

int main(int argc, char *argv[]) {
  stringstream inputInfo;
  inputInfo << cin.rdbuf();


  Graphs g1;
  g1.readGraph(inputInfo);
  //g1.print();
  g1.solveBandsize();

  return 0;
}
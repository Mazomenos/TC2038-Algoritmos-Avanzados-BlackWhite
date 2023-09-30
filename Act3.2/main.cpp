/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 29 de Septiembre del 2023



 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main < TestCases/test01.txt
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/

#include "Graph.h"
#include <iostream>
#include <sstream>

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();

  Graph g1;
  g1.readGraph(inputInfo);
  //g1.print();
  g1.Dijkstra(0);
  g1.floydWarshall(g1.MatrixGenerator());
  return 0;
}

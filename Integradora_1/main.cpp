
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

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

#define d 256

using namespace std;

vector<char> readFile(string fileName) {

  ifstream file(fileName);

  if (!file) {
    cerr << "No se pudo abrir el archivo: " << fileName << endl;
    return vector<char>();
  }

  vector<char> arr;
  char character;

  while (file.get(character)) {

    // Agregale esto si quieres q se pase el new line
    /*
    if (character == '\n'){
        continue;
    }
    */

    arr.push_back(character);
  }
  return arr;
}

void analizeTransmission(vector<vector<char>> mcodes,
                         vector<vector<char>> transmissions) {
  vector<vector<int>> indices(mcodes.size() * transmissions.size());

  int count = 0;

  for (int j = 0; j < mcodes.size(); j++) {
    for (int i = 0; i < transmissions.size(); i++) {
      int x, y;
      int p = 0;
      int t = 0;
      int h = 1;

      for (x = 0; x < mcodes[j].size() - 1; x++) {
        h = (h * d) % INT_MAX;
      }

      for (x = 0; x < mcodes[j].size(); x++) {
        p = (d * p + mcodes[j][x] % INT_MAX);
        t = (d * t + transmissions[i][x] % INT_MAX);
      }

      for (x = 0; x <= transmissions[i].size() - mcodes[j].size(); x++) {
        if (p == t) {
          for (y = 0; y < mcodes[j].size(); y++) {
            if (transmissions[i][x + y] != mcodes[j][y]) {
              break;
            }
          }
          if (y == mcodes[j].size()) {
            indices[count].push_back(x);
          }
        }

        if (x < transmissions[i].size() - mcodes[j].size()) {
          t = (d * (t - transmissions[i][x] * h) +
               transmissions[i][x + mcodes[j].size()]) %
              INT_MAX;
          if (t < 0)
            t = (t + INT_MAX);
        }
      }
      count++;
    }
  }

  for (int i = 0; i < indices.size(); i++) {
    if (indices[i].size() == 0) {
      cout << "False";
    } else {
      cout << "True ";
    }
    for (int j = 0; j < indices[i].size(); j++) {
      cout << indices[i][j] << " ";
    }
    cout << endl;
  }
}



int main() {
  string m1 = "mcode1.txt";
  string m2 = "mcode2.txt";
  string m3 = "mcode3.txt";
  string t1 = "transmission1.txt";
  string t2 = "transmission2.txt";

  vector<vector<char>> mcodes;
  vector<vector<char>> transmissions;

  vector<char> am1 = readFile(m1);
  mcodes.push_back(am1);
  vector<char> am2 = readFile(m2);
  mcodes.push_back(am2);
  vector<char> am3 = readFile(m3);
  mcodes.push_back(am3);
  vector<char> ta1 = readFile(t1);
  transmissions.push_back(ta1);
  vector<char> ta2 = readFile(t2);
  transmissions.push_back(ta2);

  // funciones de la actividad
  cout << "Parte 1" << endl;
  analizeTransmission(mcodes, transmissions);

  cout << "Parte 3" << endl;
  
  
  return 0;
}

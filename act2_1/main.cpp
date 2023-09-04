/*
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 *  ./main < TestCases/test01.txt
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Función para calcular el hash de un renglón
int calcularHash(const string &linea) {
  int suma = 0;
  for (char c : linea) {
    suma += static_cast<int>(c);
  }
  return suma % 256;
}

int main() {
  string nombreArchivo;
  char caracter;
  int n;

  cin >> nombreArchivo;
  cin >> n;

  if (n % 4 != 0 || n < 4 || n > 64) {
    cerr << "El valor de n debe ser un múltiplo de 4 entre 4 y 64." << endl;
    return 1;
  }

  ifstream archivo(nombreArchivo);

  if (!archivo) {
    cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    return 1;
  }

  vector<vector<char>> renglones;
  vector<char> conjunto;

  while (archivo.get(caracter)) {

    if (caracter == '\n') {
      continue;
    }

    conjunto.push_back(caracter);

    if (conjunto.size() == 4) {
      renglones.push_back(conjunto);
      conjunto.clear();
    }
  }

  if (!conjunto.empty()) {
    renglones.push_back(conjunto);
  }

  for (const vector<char> &conjunto : renglones) {
    for (char c : conjunto) {
      cout << c;
    }
    cout << endl;
  }

  archivo.close();

  // // Imprimir el resultado
  // std::cout << "Resultado: " << resultadoHex << std::endl;

  return 0;
}

/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 3 de Septiembre del 2023


*/


#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



/*
 * Funcion Hash
 * Esta funcion recibe la linea de strings que se genera abajo para poder
 * darnos el valor decimal del residuo de la suma para poder ser
 * convertido en hexadecimal
 */
int calcularHash(const string &linea) {
    int suma = 0;
    for (char c : linea) {
        suma += static_cast<int>(c);
    }
    return suma % 256;
}

/*
 * Main
 * Este codigo tiene una complejidad de O((tamaño del texto) + (tamaño del texto % n))
 * esto se debe a que tenemos que recorrer el texto con un while para sacar los caracters
 * y tmb tenemos q rellenar el espacio vacio del ultimo conjunto en caso de ser necesario, el cual se
 * puede representar como tamaño % n
 */
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



        conjunto.push_back(caracter);

        if (conjunto.size() == n) {
            renglones.push_back(conjunto);
            conjunto.clear();
        }
    }


    if (!conjunto.empty()) {
        while (conjunto.size() < n){
            conjunto.push_back('a');
        }
        renglones.push_back(conjunto);
    }

    int size = renglones.size() % n;

    if (size != 0){

    }


    for (const vector<char> &conjunto : renglones) {
        string linea = "";
        for (char c : conjunto) {

            linea += c;
        }

        cout << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << calcularHash(linea);
    }

    archivo.close();


    return 0;
}
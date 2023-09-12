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

vector<char> readFile(string fileName) {

    ifstream file(fileName);

    if (!file) {
        cerr << "No se pudo abrir el archivo: " << fileName << endl;
        return vector<char>();
    }

    vector<char> arr;
    char character;


    while (file.get(character)) {

        //Agregale esto si quieres q se pase el new line
        /*
        if (character == '\n'){
            continue;
        }
        */

        arr.push_back(character);
        cout << character;
    }
    return arr;
}

int main(){
    string m1 = "mcode1.txt";
    string m2 = "mcode2.txt";
    string m3 = "mcode3.txt";
    string t1 = "transmission1.txt";
    string t2 = "transmission2.txt";
    string t3 = "transmission3.txt";

    vector<char> am1 = readFile(m1);




    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

// Función para calcular el hash de un renglón
int calcularHash(const std::string& linea) {
    int suma = 0;
    for (char c : linea) {
        suma += static_cast<int>(c);
    }
    return suma % 256;
}

int main() {
    std::string nombreArchivo;
    int n;

    // Solicitar el nombre del archivo y el valor de n
    std::cout << "Ingrese el nombre del archivo de texto: ";
    std::cin >> nombreArchivo;
    std::cout << "Ingrese el valor de n (un múltiplo de 4 entre 4 y 64): ";
    std::cin >> n;

    // Verificar que n cumple con las restricciones
    if (n % 4 != 0 || n < 4 || n > 64) {
        std::cerr << "El valor de n debe ser un múltiplo de 4 entre 4 y 64." << std::endl;
        return 1;
    }

    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return 1;
    }

    std::vector<std::string> renglones;
    std::string linea;

    // Leer el archivo línea por línea y almacenar los renglones
    while (std::getline(archivo, linea)) {
        // Rellenar el renglón con 'a' si es necesario
        while (linea.length() < n) {
            linea += 'a';
        }
        renglones.push_back(linea);
    }

    archivo.close();

    // Calcular el hash y generar la representación hexadecimal
    std::string resultadoHex;

    for (const std::string& renglon : renglones) {
        int hash = calcularHash(renglon);
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << hash;
        resultadoHex += ss.str();
    }

    // Imprimir el resultado
    std::cout << "Resultado: " << resultadoHex << std::endl;

    return 0;
}

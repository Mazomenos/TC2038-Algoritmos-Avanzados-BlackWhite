/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 23 de Agosto del 2023


*/

//Includes
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>


void backtraking(std::vector<std::vector<int>> mat, int m, int n){

    // 2d vector with same dimensions as mat but filled with 0´s
    std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));

    for (std::vector<int> place : path){

        for (int nums : place){
            std::cout <<nums << " ";
        }
        std::cout << std::endl;
    }



}


int main(){
    std::string input;
    int m, n, num;


    std::cin >>m;
    std::cin >> n;


    //removes input buffer to avoid skipping over cin instructions on the first loop rotation
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::vector<int>> matrix(m);

    for (int i = 0; i<m; i++){
        std::cout << i << std::endl;
        std::getline(std::cin,input);
        std::istringstream iss(input);
        while (iss >> num){
            if (num == 0 or num == 1) {
                matrix[i].push_back(num);
            }
            else {
                std::cout << "Input contains numbers different from 1 or 0";
                return -1;
            }
        }

    }

    for (std::vector<int> place : matrix){

        for (int nums : place){
            std::cout <<nums << std::endl;
        }
    }

    //backtraking
    backtraking(matrix, m, n);

    //Ram and pound (maybe?)




    return 0;
}

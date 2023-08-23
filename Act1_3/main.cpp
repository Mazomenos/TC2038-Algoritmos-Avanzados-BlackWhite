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


void backtraking(std::vector<std::vector<int>> mat, std::vector<std::vector<int>> path , int m, int n, int x, int y){

    // 2d vector with same dimensions as mat but filled with 0´s




    //accept
    if (x == m-1 and y == n-1){
        path[x][y] = 1;


        for (std::vector<int> place : path){

            for (int nums : place){
                std::cout <<nums << " ";
            }
            std::cout << std::endl;
        }

    }

        //deny
        if (x < 0 or y < 0 or x >= m or y >= n) {
            return;
        }
        if (mat[x][y] == 0) {
            path[x][y] = 0;
            return;
        }
        path[x][y] = 1;

        //loop
        backtraking(mat, path, m, n, x + 1, y); //down
        if (path[x][y+1] != 1){
            backtraking(mat, path, m, n, x, y + 1); //right
        }
        if (x != m-1 and y != n-1) {
            backtraking(mat, path, m, n, x, y - 1); //left
        }


}

void branch_bound(){


}


int main(){
    std::string input;
    int m, n, num;
    int x = 0, y = 0;

    std::cin >>m;
    std::cin >> n;


    //removes input buffer to avoid skipping over cin instructions on the first loop rotation
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::vector<int>> matrix(m);
    std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));

    for (int i = 0; i<m; i++){
        //std::cout << i << std::endl;
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
    /*
    for (std::vector<int> place : matrix){

        for (int nums : place){
            std::cout <<nums << std::endl;
        }
    }
     */

    //backtraking
    backtraking(matrix, path , m, n, x, y);

    //Ram and pound (maybe?)

    std::cout << "hello";


    return 0;
}

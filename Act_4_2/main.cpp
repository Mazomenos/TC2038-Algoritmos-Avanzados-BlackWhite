//
// Created by gustb on 14/11/2023.
//

#include <iostream>

struct Point {
    int x, y;
};




int main(){
    int x, y, n, c;
    std::cin >> n;
    std::cin >> c;

    if (n < 3){
        std::cout << "Numero de arboles menor a 3, no hay solucion posible"  << std::endl;
        return 0;
    }

    Point pointsList[n];
    for (int i = 0; i < n; i++){
        std::cin >> x >> y;

        pointsList[i] = {x, y};
    }
    /*
    for (int i = 0; i < n; i++){
        std::cout << "Point " << i + 1 << ": "  << pointsList[i].x  << " " << pointsList[i].y << std::endl;
    }
    */

    //INSERTAR FUNCION PRO AQUI

    return 0;
}
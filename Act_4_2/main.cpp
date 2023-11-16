/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 16 de Noviembre del 2023

**/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

class Point {
    private:
        double x, y;

    public:
        Point();
        Point(double a, double b);
        Point(const Point& dot);
        double getX() const;
        double getY() const;


};

Point::Point() {

}

Point::Point(double a, double b) {
    x = a;
    y = b;
}

Point::Point(const Point& dot){
    x = dot.x;
    y = dot.y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double distance(const Point &p1, const Point &p2){
    double diffx = p2.getX() - p1.getX();
    double diffy = p2.getY() - p1.getY();
    return sqrt((diffx * diffx) + (diffy * diffy));
}

int orientacion(const Point &p, const Point &q, const Point &r){
    int result;



    result = (q.getX() - p.getX()) * (r.getY() - p.getY()) -
             (r.getX() - p.getX()) * (q.getY() - p.getY());



    return result;
}

bool comparePoints(const Point &p1, const Point &p2) {
    if (p1.getX() == p2.getX()) {
        return p1.getY() < p2.getY();
    } else {
    return p1.getX() < p2.getX();
    }
}


double ConvexHull(std::vector<Point> points, int n, float c){

    std::vector<Point> hullUpper;
    std::vector<Point> hullLower;
    std::vector<Point> hull;

    std::sort(points.begin(), points.end(), comparePoints);

    hullUpper.push_back(points[0]);
    hullUpper.push_back(points[1]);

    for (int i = 2; i < n; i++){

        hullUpper.push_back(points[i]);

        while (hullUpper.size() > 2 and (orientacion(hullUpper[hullUpper.size() - 3], hullUpper[hullUpper.size() -2], hullUpper[hullUpper.size() - 1]) > 0)){

            hullUpper.erase(hullUpper.begin() + (hullUpper.size() - 2));

        }
    }

    //hola papu


    hullLower.push_back(points[n-1]);
    hullLower.push_back(points[n-2]);

    for (int i = n - 3; i >= 0; i--){
        hullLower.push_back(points[i]);



        while (hullLower.size() > 2 and (orientacion(hullLower[hullLower.size() - 3], hullLower[hullLower.size() - 2], hullLower[hullLower.size() - 1]) > 0)){
            hullLower.erase(hullLower.begin() + (hullLower.size() - 2));


        }
    }


    hullLower.erase(hullLower.begin() + 0);
    hullLower.pop_back();


    hull = hullUpper;




    for (const auto & i : hullLower){
        hull.push_back(i);
    }



    //Calcular distancias

    int i = 0;
    int j = 1;
    double suma = 0;

    //THIS LOOP GOES FROM PAIR TO PAIR OF INDEXES AND
    //SUMS THE WEIGHT VALUE BETWEEN THE 2 TO CA
    while (i < hull.size() and j < hull.size()){

        double medida = distance(hull[i],hull[j]);
        suma += (medida*c);


        i++;
        j++;

    }

    double medida = distance(hull[0],hull[j-1]);
    suma += (medida*c);

    return suma;
}

int main(){
    int n;
    float x, y, c;
    std::cin >> n;
    std::cin >> c;

    if (n < 3){
        std::cout << "Numero de arboles menor a 3, no hay solucion posible"  << std::endl;
        return 0;
    }

    std::vector<Point> pointsList;
    for (int i = 0; i < n; i++){
        std::cin >> x >> y;

        pointsList.push_back({x, y});
    }

    //INSERTAR FUNCION PRO AQUI
    double result = ConvexHull(pointsList, n, c);

    printf("%.2f\n", result);

    return 0;
}
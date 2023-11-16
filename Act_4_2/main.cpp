/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 16 de Noviembre del 2023

**/

//LIBRERIAS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

//CLASE PUNTO QUE SE USA PARA REPRESENTAR PUNTOS
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

//DEFAULT CONSTRUCTOR
Point::Point() {

}

//CONSTRUCTOR AL DAR X Y
Point::Point(double a, double b) {
    x = a;
    y = b;
}

//CONSTRUCTOR AL RECIBIR OBJETO DIRECTO
Point::Point(const Point& dot){
    x = dot.x;
    y = dot.y;
}

//FUNCION PARA OBTENER VALOR DE X
double Point::getX() const {
    return x;
}

//FUNCION PARA OBTENER VALOR Y
double Point::getY() const {
    return y;
}

//FUNCION QUE CALCULA LA DISTANCE ENTRE 2 PUNTOS EN UN PLANO 2D
//Y DEVUELVE EL RESULTADO COMO DOUBLE
double distance(const Point &p1, const Point &p2){
    double diffx = p2.getX() - p1.getX();
    double diffy = p2.getY() - p1.getY();
    return sqrt((diffx * diffx) + (diffy * diffy));
}

/* FUNCION QUE CALCULA LA ORIENTACION ENTRE 3 PUNTOS CON EL
 * CALCULO DEL DETERMINANTE, DEVOLVIENDO LA ORIENTACION
 * RESULT <  0 : IZQUIERDA
 * RESULT >  0 : DERECHA
 * RESULT == 0 : COLINEAL
*/
int orientacion(const Point &p, const Point &q, const Point &r){
    int result;

    result = (q.getX() - p.getX()) * (r.getY() - p.getY()) -
             (r.getX() - p.getX()) * (q.getY() - p.getY());

    return result;
}

/* FUNCION AUXILIAR PARA EL SORT
 * Esta dicta que se organizen los puntos de menor a mayor valor x,
 * En caso de que se a el mismo valor de x, agarra el que tenga menor valor de y.
*/
bool comparePoints(const Point &p1, const Point &p2) {
    if (p1.getX() == p2.getX()) {
        return p1.getY() < p2.getY();
    } else {
    return p1.getX() < p2.getX();
    }
}

/*
 * FUNCION PRINCIPAL DEL PROBLEMA, ESTE RECIBE UN VECTOR DE PUNTOS, EL NUMERO DE PUNTOS
 * EN EL VECTOR, Y EL VALOR DE PRECIO POR METRO DE CERCO, DEVOLVIENDONOS EL COSTO DE CERCA.
 */
double ConvexHull(std::vector<Point> points, int n, float c){

    //INICIALIZACION DE CUBIERTAS
    std::vector<Point> hullUpper;
    std::vector<Point> hullLower;
    std::vector<Point> hull;

    //ORDENAMIENTO DE PUNTOS BASADO EN VALORES X (Y EN EMPATES)
    std::sort(points.begin(), points.end(), comparePoints);

    //CUBIERTA SUPERIOR

    //SE METEN LOS PRIMERO 2 VALORES A LA LISTA DE LA CUBIERTA SUPERIOR
    hullUpper.push_back(points[0]);
    hullUpper.push_back(points[1]);

    //SE LOOPEA POR TODA LA LISTA DE PUNTOS
    for (int i = 2; i < n; i++){

        hullUpper.push_back(points[i]);

        while (hullUpper.size() > 2 and (orientacion(hullUpper[hullUpper.size() - 3], hullUpper[hullUpper.size() -2], hullUpper[hullUpper.size() - 1]) > 0)){

            hullUpper.erase(hullUpper.begin() + (hullUpper.size() - 2));

        }
    }

    //CUBIERTA INFERIOR

    //SE METEN LOS ULTIMOS 2 VALORES A LA LISTA DE LA CUBIERTA SUPERIOR
    hullLower.push_back(points[n-1]);
    hullLower.push_back(points[n-2]);

    for (int i = n - 3; i >= 0; i--){
        hullLower.push_back(points[i]);



        while (hullLower.size() > 2 and (orientacion(hullLower[hullLower.size() - 3], hullLower[hullLower.size() - 2], hullLower[hullLower.size() - 1]) > 0)){
            hullLower.erase(hullLower.begin() + (hullLower.size() - 2));


        }
    }


    //SE BORRAN EL PRIMER Y ULTIMO VALOR DE LA CUBIERTA INFERIOR
    hullLower.erase(hullLower.begin() + 0);
    hullLower.pop_back();


    //SE COMBINAN LAS DOS CUBIERTAS

    hull = hullUpper;
    for (const auto & i : hullLower){
        hull.push_back(i);
    }

    //Calculo de distancias y suma

    int i = 0;
    int j = 1;
    double suma = 0;

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

/*
 * ESTE CODIGO USA EL METODO DE GRAHAM´S SCAN QUE VIMOS EN CLASE, CREANDO LA CUBIERTA
 * SUPERIOR E INFERIOR, Y DEPSUES JUNTANDOLAS PARA OBTENER LA COMPLETA.
 *
 * TIENE UNA COMPLEJIDAD DE TIEMPO DE O(nLOG(n)) YA QUE EL ALGORITMO DE std::sort TIENE
 * ESTA COMPLEJIDAD PARA ORDENAR LOS PUNTOS, CON LA CREACION DE LA CUBIERTA SIENDO O(n),
 * YA QUE TIENE Q PASAR POR TODOS LOS PUNTOS PARA CREARLA.
 */
int main(){
    int n;
    float x, y, c;
    std::cin >> n;
    std::cin >> c;

    if (n < 3){
        std::cout << "Numero de arboles menor a 3, no hay solucion posible"  << std::endl;
        return 0;
    }

    //CREACION DE LISTA
    std::vector<Point> pointsList;
    for (int i = 0; i < n; i++){
        std::cin >> x >> y;

        pointsList.push_back({x, y});
    }

    double result = ConvexHull(pointsList, n, c);

    //PRINT DE VALOR FORMATEADO A 2 DECIMALES
    printf("%.2f\n", result);

    return 0;
}
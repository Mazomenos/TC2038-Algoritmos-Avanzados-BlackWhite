/*
Equipo:  

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038 

Fecha 10 de Agosto del 2023


*/

#include <iostream>

using namespace std;

/*
Esta funcion recibe los indices de las partes divididas del algortimo que 
y los ordena y acomoda en el arreglo.
*/
void merge(int lista[], int inicio, int mitad, int final) {

    /*Se inicialian las variables
    i = contador del lado izquierdo
    j = contador del lado derecho
    k = contador de la lista temporal
    size = tamaño de la muestra
    temp[] = arreglo temporal
    */ 
    int i = inicio, j = mitad + 1, k = inicio, size = final - inicio;
    int temp[size];

    /* 
    Este primer while compara los elementos entre derecha y izquierda y los acomoda
    de menor a mayor
    */
    while (i<=mitad && j<=final){
        if (lista[i] <= lista[j]){
            temp[k] = lista[i];
            i++, k++;
        }
        else {
            temp[k] = lista[j];
            j++, k++;
        }
    }

    /*
    Este while agrega los valores restantes de la izquierda 
    */
    while (i<=mitad) {
        temp[k] = lista[i];
            i++, k++;
    }

    /*
    Este while agrega los valores restantes de la derecha 
    */
    while (j<=final) {
        temp[k] = lista[j];
            j++, k++;
    }

    /*
    Copia la lista temporal a la lista base
    */
    for (int p=inicio; p<=final; p++){
        lista[p] = temp[p];
    }

}

 
/*
Esta funcion recursiva recibe los indices de la lista para ir sabiendo como dividirlo 
en partes mas chicas, y luego manda los indices al merge para que pueda acomodar los elementos de la division
y mandarlos a ordenar con los otros
*/
void mergesort(int lista[], int inicio, int final){

    if (inicio >= final) {
        return;
    }

    int mitad = (final + inicio) / 2;
    
    mergesort(lista, inicio, mitad);
    mergesort(lista, mitad + 1 , final);
    merge(lista, inicio, mitad, final);

}



int main() {
    //Se declaran las variables del contador y de n (size)
    int i,n;
    //Ingresar n (size)
    cin >> n;
    int list[n];
    for (i = 0; i < n; i++) {
        cin >> list[i];
    }
    mergesort(list, 0, n-1);

    for (i = 0; i < n; i++) {
        cout << list[i] << endl;
    }

    //return main
    return 0;
}

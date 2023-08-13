/*

Karatsuba

Divide and Conquer


*/


#include <iostream>

using namespace std;

//Funcion que calcula la multiplicacion por el metodo de Karatsuba
int karatsuba(int x, int y){


    if (x < 10 or y < 10){
        return x * y;
    }

    
    else {
    
       return 0; 
    }
}


int main() {
    
    int a,b,ab;

    cout << "Karatsuba" << endl;

    cin >> a;
    cin >> b;

    ab = karatsuba(a,b);

    cout << a << " " << b << endl;

    cout << ab;

    //Ending return
    return 0;
}
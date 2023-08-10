#include <iostream>

using namespace std;



int main() {
    int i,size;
    cout << "Hello World!";
    cin >> size;
    int list[size];
    for (i = 0; i < size; i++) {
        cin >> list[i];
    }
    for (i = 0; i < size; i++) {
        cout << list[i];
    }
    return 0;
}
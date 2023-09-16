
/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 3 de Septiembre del 2023

Compilacion para ejecucion:
 g++ -std=c++17 -O3 -o main *.cpp
Ejecucion:
 ./main < test01.txt

*/

#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include <vector>

#define d 256

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

    // Agregale esto si quieres q se pase el new line
    
    if (character == '\n'){
        continue;
    }

    arr.push_back(character);
  }
  return arr;
}

// codigo basado y sacado de geeksforgeeks 
// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
void analizeTransmission(vector<vector<char>> mcodes,
                         vector<vector<char>> transmissions) {
  vector<vector<int>> indices(mcodes.size() * transmissions.size());

  int count = 0;

  for (int j = 0; j < mcodes.size(); j++) {
    for (int i = 0; i < transmissions.size(); i++) {
      int x, y;
      int p = 0;
      int t = 0;
      int h = 1;

      for (x = 0; x < mcodes[j].size() - 1; x++) {
        h = (h * d) % INT_MAX;
      }

      for (x = 0; x < mcodes[j].size(); x++) {
        p = (d * p + mcodes[j][x] % INT_MAX);
        t = (d * t + transmissions[i][x] % INT_MAX);
      }

      for (x = 0; x <= transmissions[i].size() - mcodes[j].size(); x++) {
        if (p == t) {
          for (y = 0; y < mcodes[j].size(); y++) {
            if (transmissions[i][x + y] != mcodes[j][y]) {
              break;
            }
          }
          if (y == mcodes[j].size()) {
            indices[count].push_back(x);
          }
        }

        if (x < transmissions[i].size() - mcodes[j].size()) {
          t = (d * (t - transmissions[i][x] * h) +
               transmissions[i][x + mcodes[j].size()]) %
              INT_MAX;
          if (t < 0)
            t = (t + INT_MAX);
        }
      }
      count++;
    }
  }

  for (int i = 0; i < indices.size(); i++) {
    if (indices[i].size() == 0) {
      cout << "False";
    } else {
      cout << "True ";
    }
    for (int j = 0; j < indices[i].size(); j++) {
      cout << indices[i][j] << " ";
    }
    cout << endl;
  }
}

void LCSub(vector<vector<char>> transmissions) {
  int lenTrans01 = transmissions[0].size();
  int lenTrans02 = transmissions[1].size();

  vector<vector<int>> LCSuff(lenTrans01 + 1, vector<int>(lenTrans02 + 1));
  int len = 0;
  int row = 0, col = 0;
  for (int i = 0; i <= lenTrans01; i++) {
    for (int j = 0; j <= lenTrans02; j++) {
      if (i == 0 || j == 0)
        LCSuff[i][j] = 0;
      else if (transmissions[0][i - 1] == transmissions[1][j - 1]) {
        LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
        if (LCSuff[i][j] > len) {
          len = LCSuff[i][j];
          row = i;
          col = j;
        }
      } else
        LCSuff[i][j] = 0;
    }
  }
  if (len == 0) {
    cout << "No existe un substring comun mas largo" << endl;
    return;
  }
  string resultStr(len + 1, ' ');

  cout << row - resultStr.length() + 1 << " " << row - 1 << " ";
  while (LCSuff[row][col] != 0) {
    resultStr[--len] = transmissions[0][row - 1];
    row--;
    col--;
  }
  cout << resultStr << endl;
}


//--------------------------------------------------------------------------------------------

/*
 * Parte 2: Palindromos mortales
 * Esta funcion recibe un vector de char y nos imprime el palindromo mas grande que se tiene
 * dentro del vector.
 * Tiene una complejidad de tiempo de O(n)
 * 
 * Codigo basado en articulos siguientes articulos e implementacion:
 * https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
 * https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-2/
 * https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-3-2/
 */

void palindromoMaligno(vector<char> text)
{

    //Inicializacion de variables
    int N = text.size();
    if (N == 0)
        return;
    N = 2 * N + 1; // Position count
    int L[N]; // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; // centerPosition
    int R = 2; // centerRightPosition
    int i; // currentRightPosition
    int iMirror;  // currentLeftPosition
    bool expand;
    int diff;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start;
    int end;

    for (i = 2; i < N; i++) {

        //Se calcula el valor simetrico
        //de la izquierda basado en i
        iMirror = 2 * C - i;

        expand = false;
        diff = R - i;

        //Si R es mayor a i
        //Aplica para las partes del texto ya exploradas
        if (diff >= 0) {

            /*  Este if usa el valor guardado en el espejo izquierdo de i
                en caso de que el valor de este sea menor a la diferencia
                entre R menos i, o en el caso de que se llegue al final del
                arreglo.

                Este solo guarda el valor simetrico del espejo a su contraparte
                a la izquierda (dinamico), sin necesidad de expandir.

            */
            if (L[iMirror] < diff || L[iMirror] == diff && R == N - 1)
                L[i] = L[iMirror];

            /*  En este if checa si estamos dentro del limite del vector y que el
                valor espejeado sea igual a la diferencia de R - i.
                Cuando se da este, usa el valor espejeado para llenar su correspondiente a
                la derecha y como aun no llega al limite, le dice que puede expandirse.

             */
            else if (L[iMirror] == diff && R < N - 1) {
                L[i] = L[iMirror];

                // Expansion required
                expand = true;
            }


            /*  En este if checa si el valor espejeado es mayor
                que la diferencia entre R - i, y le asignamos a
                la posicion i el valor de la diferencia y le
                decimos que puede expandir

             */
            else if (L[iMirror] > diff) {
                L[i] = diff;

                // Expansion required
                expand = true;
            }
        }

        //Este else aplica cuando vamos por una parte del texto no explorada
        else {
            L[i] = 0;

            // Expansion required
            expand = true;
        }

        //Se empieza el proceso de expandir el centro para buscar el largo maximo del palindromo
        //basado en este
        if (expand) {

            /*
             * Se pone una iteracion while la cual busca que se cumplan los siguientes requisitos:
             *
             * Que esten dentro de los limites del texto base
             * Ultima posicion derecha mas larga explorada dentro de N (i + L[i]) < N
             *
             * Que el valor simetrico hacia atras sea mayor a 0 (i - L[i]) > 0
             *
             * ((i + L[i]) < N && (i - L[i]) > 0)
             *
             * and &&
             *
             * Ya que se tiene que los limites estan dentro del texto recibido,
             * se checa primero si es par para darle un 1 directo y luego ya se checa la similitud entre los
             * lados derecho y izquierdo del centro
             *
             * Checa si la posicion es par (i + L[i] + 1) % 2 == 0)
             *
             * or ||
             *
             * Checa si el char en la posicion derecha es igual al de la izquierda (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2]
             *
             * ((i + L[i] + 1) % 2 == 0) || (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2])
             */

            while (((i + L[i]) < N && (i - L[i]) > 0)
                   && (((i + L[i] + 1) % 2 == 0)
                       || (text[(i + L[i] + 1) / 2]
                           == text[(i - L[i] - 1) / 2]))) {
                L[i]++;
            }
        }

        // Actualiza valores maximos
        if (L[i] > maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        //En el caso de que la expansion sobrepase
        //el limite explorado, se recalcula el
        //centro y el limite explorado
        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }

    }

    //Calcula la posicion inicial y la parte a la mitad para q tenga el indice correcto
    start = (maxLPSCenterPosition - maxLPSLength) / 2;

    end = start + maxLPSLength - 1;
    
    cout << start << " " << end << " ";

    for (i = start; i <= end; i++)
        cout << text[i];
    cout << endl;
}


//--------------------------------------------------------------------------------------------


int main() {
  string m1 = "mcode1.txt";
  string m2 = "mcode2.txt";
  string m3 = "mcode3.txt";
  string t1 = "transmission1.txt";
  string t2 = "transmission2.txt";

  vector<vector<char>> mcodes;
  vector<vector<char>> transmissions;

  vector<char> am1 = readFile(m1);
  mcodes.push_back(am1);
  vector<char> am2 = readFile(m2);
  mcodes.push_back(am2);
  vector<char> am3 = readFile(m3);
  mcodes.push_back(am3);
  vector<char> ta1 = readFile(t1);
  transmissions.push_back(ta1);
  vector<char> ta2 = readFile(t2);
  transmissions.push_back(ta2);

  cout << "Parte 1" << endl;
  analizeTransmission(mcodes, transmissions);

  cout << "Parte 2" << endl;
    palindromoMaligno(transmissions[0]);
    palindromoMaligno(transmissions[1]);

  cout << "Parte 3" << endl;
  LCSub(transmissions);
  
  return 0;
}

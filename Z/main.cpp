/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 24 de Agosto del 2023


REFERENCES:

Code based on article:
https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

The test cases provided in this study were created with the assistance of an AI language
model (GPT-3) to ensure comprehensive coverage of scenarios for pattern matching algorithm
validation. The model's responses were utilized to generate a variety of test cases, including
complex scenarios and edge cases.


*/


#include<iostream>
using namespace std;

void getZarr(string str, int Z[]);


int search(string text, string pattern)
{

    string concat = pattern + "$" + text;
    int l = concat.length();


    int Z[l];
    getZarr(concat, Z);


    for (int i = 0; i < l; ++i)
    {

        if (Z[i] == pattern.length())
            return i - pattern.length() -1;
    }

    return -1;
}




void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;


    L = R = 0;
    for (int i = 1; i < n; ++i)
    {

        if (i > R)
        {
            L = R = i;


            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {

            k = i-L;


            if (Z[k] < R-i+1)
                Z[i] = Z[k];


            else
            {

                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}


/*
 This algorithm has a time complexity of O(n+m) because it has to traverse the concatenation of p and t,
 giving us p+t.

 This algorithm is a very close variant of the one from geeks for geeks that adapts the input to take
 more complex tests and changed the function to return an int (the result).

 It uses a concatenated string of the pattern and text and iterates through it with a counter, and also
 uses variables l and r to check on the start of the string and compare to get the number of characters
 that are a match on every point of the array that has the same length as the concatenated string.
 */

int main()
{

    string T, P;
    std::getline(cin, T);
    std::getline(cin, P);



    int result = search(T, P);

    cout << result << endl;



    return 0;
}
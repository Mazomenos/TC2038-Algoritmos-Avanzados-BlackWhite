/*
Equipo:  

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038 

Fecha 10 de Agosto del 2023


*/

//Imported resources and libraries
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

/*
This function creates 2 temporary vectors with the divided items and
then merges them form higher to lower numbers, modifying the main array
with the correct order
*/
void merge(std::vector<int> &arr, int first, int mid, int last) {
  int val1 = mid - first + 1;
  int val2 = last - mid;


  std::vector<int> leftArr(val1);
  std::vector<int> rightArr(val2);

  
  for (int i = 0; i < val1; i++)
    leftArr[i] = arr[first + i];
  for (int j = 0; j < val2; j++)
    rightArr[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = first;

  while (i < val1 && j < val2) {
    if (leftArr[i] >= rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < val1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < val2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

/*
This function recursively splits the main list in halves and then
sends them to the merge function
*/
void mergeSort(std::vector<int> &arr, int first, int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    merge(arr, first, mid, last);
  }
}

// Main time complexity is T(n) = 2T(n/2) + θ(n)
int main(void) {
  int i, size;
  std::cin >> size;
  std::cout << "Size: " << size << std::endl;
  std::vector<int> myVector(size);


    for (i = 0; i < size; i++) {
      std::cin >> myVector[i];
    }

  mergeSort(myVector, 0, size - 1);

  std::cout << "Sorted: ";
  for (int num : myVector) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

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

void mergeSort(std::vector<int> &arr, int first, int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    merge(arr, first, mid, last);
  }
}

// Main time complexity is T(n) = 2T(nlog(n) + θ(n)
int main(void) {
  int i, size, flag;
  std::cin >> size;
  std::cout << "Size: " << size << std::endl;
  std::cin >> flag;
  std::cout << "Flag: " << flag << std::endl;
  std::vector<int> myVector(size);

  if (flag) {
    for (i = 0; i < size; i++) {
      std::cin >> myVector[i];
      std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  mergeSort(myVector, 0, size - 1);

  std::cout << "Sorted: ";
  for (int num : myVector) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

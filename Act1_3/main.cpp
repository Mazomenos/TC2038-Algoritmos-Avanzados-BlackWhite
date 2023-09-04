/*
Equipo:

Integrantes:

- Gustavo Betancourt Mazomenos A01252832

- Alejandro Jauregui Zarate A01252368

TC2038

Fecha 23 de Agosto del 2023


*/

// Includes
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

void backtraking(std::vector<std::vector<int>> mat,
                 std::vector<std::vector<int>> path, int m, int n, int x,
                 int y) {

  // 2d vector with same dimensions as mat but filled with 0´s

  // std::cout << x << " " << y <<  std::endl;

  // accept
  if (x == m - 1 and y == n - 1) {
    path[x][y] = 1;

    for (std::vector<int> place : path) {

      for (int nums : place) {
        std::cout << nums << " ";
      }
      std::cout << std::endl;
    }
    path[x][y] = 0;
  }

  // deny
  if (x < 0 or y < 0 or x >= m or y >= n) {

    return;
  }

  if (mat[x][y] == 0) {
    path[x][y] = 0;
    return;
  }
  path[x][y] = 1;

  // loop
  if (x + 1 <= m - 1) {
    if (path[x + 1][y] != 1) {

      backtraking(mat, path, m, n, x + 1, y); // down
    }
  }

  if (path[x][y + 1] != 1) {
    // path[x][y+1] != 1 or y + 1 == n-1

    backtraking(mat, path, m, n, x, y + 1); // right
  }
  if (x != m - 1 and y != n - 1) {

    backtraking(mat, path, m, n, x, y - 1); // left
    backtraking(mat, path, m, n, x - 1, y); // up
  }
}

bool canVisit(int x, int y, int m, int n, std::vector<std::vector<int>> &mat) {
  return x >= 0 && y >= 0 && x < m && y < n && mat[x][y] == 1;
}

int calculateHeuristic(int x, int y, int m, int n) {
  int remainingRows = m - 1 - x;
  int remainingCols = n - 1 - y;
  return remainingRows + remainingCols;
}

void branch_bound(std::vector<std::vector<int>> &mat,
                  std::vector<std::vector<int>> &path, int m, int n, int x,
                  int y, std::vector<std::vector<bool>> &visited) {
    if (x == m - 1 && y == n - 1) {
        path[x][y] = 1;

        for (const std::vector<int> &row : path) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    if (!canVisit(x, y, m, n, mat) || visited[x][y]) {
        return;
    }

    int heuristic = calculateHeuristic(x, y, m, n);

    if (heuristic > (m * n)) {
        return;
    }

    path[x][y] = 1;
    visited[x][y] = true;

    if (canVisit(x + 1, y, m, n, mat)) {
        branch_bound(mat, path, m, n, x + 1, y, visited);
    }

    if (canVisit(x, y + 1, m, n, mat)) {
        branch_bound(mat, path, m, n, x, y + 1, visited);
    }

    if (canVisit(x, y - 1, m, n, mat)) {
        branch_bound(mat, path, m, n, x, y - 1, visited);
    }

    if (canVisit(x - 1, y, m, n, mat)) {
        branch_bound(mat, path, m, n, x - 1, y, visited);
    }

    path[x][y] = 0;
    visited[x][y] = false;
}


int main() {
  std::string input;
  int m, n, num;
  int x = 0, y = 0;

  std::cin >> m;
  std::cin >> n;

  // removes input buffer to avoid skipping over cin instructions on the first
  // loop rotation
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::vector<std::vector<int>> matrix(m);
  std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    // std::cout << i << std::endl;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> num) {
      if (num == 0 or num == 1) {
        matrix[i].push_back(num);
      } else {
        std::cout << "Input contains numbers different from 1 or 0";
        return -1;
      }
    }
  }
  /*
  for (std::vector<int> place : matrix){

      for (int nums : place){
          std::cout <<nums << std::endl;
      }
  }
   */

  std::cout << "Branch&Bound: \n";
  branch_bound(matrix, path, m, n, x, y, visited);
  
  path.assign(m, std::vector<int>(n, 0));
  
  std::cout << "Backtracking: \n";
  backtraking(matrix, path, m, n, x, y);

  return 0;
}

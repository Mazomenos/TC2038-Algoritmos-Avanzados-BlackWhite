#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Graphs {
private:
  int numNodes, numEdges;

  std::vector<std::list<int>> adjListGraph;

  std::vector<int> bestSolution;

  void split(std::string line, std::vector<int> &res);

  int calculateBandsize(const std::vector<int> &labels);

  std::vector<int> generateRandomSolution();


public:
  Graphs();
  ~Graphs();
  void readGraph(std::istream &input);
  void print();
  void solveBandsize(int maxIterations);
};

#endif // _GRAPHS_H_
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Graph {
private:
  int numNodes;
  int numEdges;

  std::vector<std::list<std::pair<int, int>>> adjList;

  void split(std::string line, std::vector<int> &res);

public:
  Graph();
  ~Graph();
  void readGraph(std::istream &input);
  void print();
  void Dijkstra(int source);
  std::vector<std::vector<int>> MatrixGenerator();
  void floydWarshall(std::vector<std::vector<int>> D);
};

#endif // _GRAPH_H_

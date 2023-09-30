
#include "Graph.h"

Graph::Graph() {
  adjList.clear();
  numEdges = 0;
  numNodes = 0;
}

Graph::~Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
}

void Graph::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::readGraph(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];

      adjList.resize(numNodes);

      for (int k = 0; k < numNodes; k++) {
        std::list<std::pair<int, int>> tmpList;
        adjList[k] = tmpList;
      }
      i++;
      continue;
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0] - 1;
    int v = res[1] - 1;
    int weight = res[2];
    adjList[u].push_back(std::make_pair(v, weight));
    i++;
  }
}

void Graph::print() {
  std::cout << "Adjacency List" << std::endl;
  for (int u = 0; u < numNodes; u++) {
    std::cout << "vertex " << u + 1 << ":"; // convierte nodo a uno-basado
    std::list<std::pair<int, int>> g = adjList[u];
    std::list<std::pair<int, int>>::iterator it;
    for (it = g.begin(); it != g.end(); ++it) {
      std::pair<int, int> par = *it;
      // convierte nodo a uno-basado
      std::cout << '\t' << "{" << par.first + 1 << "," << par.second << "}";
    }
    std::cout << std::endl;
  }
}

// la complejidad algoritmica del algoritmo de Dijkstra se puede entender en diversas partes donde podemos verlo como el bucle principal hace el recorrido
// por la cantidad de nodos donde luego hace el recorrido de O(E) donde E es el numero de aristas para luego ver que las operaciones de insercion  
// y modificaciones del conjunto 'unvisited' se puede ver como O(log V) por lo que al final podemos entender la complejidad algoritmica como 
// O((E+V)*log(V))

void Graph::Dijkstra(int source) {
  const int INF = std::numeric_limits<int>::max();

  std::cout << "Dijkstra, shortest paths from source vertex " << std::endl;

  std::vector<int> distance(numNodes, std::numeric_limits<int>::max());
  std::vector<int> parent(numNodes, -1);
  std::set<int> visited;

  distance[source] = 0;

  std::set<std::pair<int, int>> unvisitedNodes;
  unvisitedNodes.insert({0, source});

  while (!unvisitedNodes.empty()) {
    int currentNode = unvisitedNodes.begin()->second;
    unvisitedNodes.erase(unvisitedNodes.begin());

    visited.insert(currentNode);

    for (const auto &neighbor : adjList[currentNode]) {
      int nextNode = neighbor.first;
      int edgeWeight = neighbor.second;

      if (visited.find(nextNode) == visited.end() &&
          (distance[currentNode] + edgeWeight) < distance[nextNode]) {

        distance[nextNode] = distance[currentNode] + edgeWeight;
        parent[nextNode] = currentNode;

        unvisitedNodes.insert({distance[nextNode], nextNode});
      }
    }
  }

  for (int i = 0; i < numNodes; ++i) {
    if (distance[i] == std::numeric_limits<int>::max()) {
      distance[i] = INF;
    }
    std::cout << i + 1 << ": " << distance[i] << std::endl;
  }
}

std::vector<std::vector<int>> Graph::MatrixGenerator() {
    int value;
    int j;


    //N de vertices
    int n = adjList.size();
    std::vector<std::vector<int>> D(n, std::vector<int>(n, 1000));
    //vertice
    //int i = 0;
    //paso de lista de adjacencia
    //int paso = 1;

    for (int i = 0; i<n; i++){
        //std::cout << "DONE" << std::endl;
        //std::cout << n << std::endl;
        for (int paso = 0; paso < adjList[i].size(); paso++){
            std::list<std::pair<int, int>>::iterator it = std::next(adjList[i].begin(), paso);

            //Peso
            value = it->second;
            //Vertice
            j = it->first;
            D[i][j] = value;
            //std::cout << "Valor de D[" <<i+1 << "][" << j+1 << "] " << D[i][j] << std::endl;
        }
        D[i][i] = 0;
        //std::cout << "Valor de D[" <<i+1 << "][" << i+1 << "] " << D[i][i] << std::endl;
    }

    return D;
}

void Graph::floydWarshall(std::vector<std::vector<int>> D){
    int n = D.size();
    std::cout << "Floyd-Warshall, all pairs shortest path" << std::endl;

    for (int k = 0; k<n; k++){
        for (int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if (D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }

    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (D[i][j] == 1000){
                std::cout << "INF ";
            } else
                std::cout << D[i][j] << "   ";
        }
        std::cout << std::endl;
    }


}

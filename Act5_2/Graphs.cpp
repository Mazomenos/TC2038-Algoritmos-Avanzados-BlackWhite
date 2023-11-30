#include "Graphs.h"

Graphs::Graphs() {
  adjListGraph.clear();
  numNodes = 0;
  numEdges = 0;
}

Graphs::~Graphs() {
  adjListGraph.clear();
  numNodes = 0;
  numEdges = 0;
}

void Graphs::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graphs::readGraph(std::istream &input) {
  std::string line;
  int i = 0, j = 0, u, v;

  while (getline(input, line)) {
    if (i == 0) {
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[1];
      adjListGraph.resize(numNodes);

      for (int k = 0; k < numNodes; k++) {
        std::list<int> tmpList;
        adjListGraph[k] = tmpList;
      }
      i++;
      continue;
    }

    std::vector<int> res;
    split(line, res);

    u = res[0] - 1; // convierte nodo a cero-basado
    v = res[1] - 1; // convierte nodo a cero-basado

    adjListGraph[u].push_back(v);

    i++;
  }
}

// Imprime grafo por vertice
void Graphs::print() {
  std::cout << "Listado: " << std::endl;
  for (int u = 0; u < numNodes; u++) {
    std::cout << "vertex " << u + 1 << ":"; // convierte nodo a uno-basado
    std::list<int> g = adjListGraph[u];
    std::list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it) {
      int val = *it;
      // convierte nodo a uno-basado
      std::cout << ' ' << "{" << val + 1 << "}";
    }
    std::cout << std::endl;
  }
}

/////////////////////////////////////////////////////

// La complejidad de la funcion que es basicamente lo que corre todas las demas funciones declaradas abajo, tiene una complejidad de O(n^2 * Iteraciones) donde n es el numero de nodos del grafo, esto porque por default tiene que ver todos los nodos del grafo y sus combinaciones al igual que esto esta dentro de un ciclo donde en el peor de los casos, tendria que correr sobre el numero de iteraciones. Por lo que por todo el codigo se podria ver de la siguiente manera: O(n + n^2 * n^2 * iteraciones) o O(n^4 * iteraciones)

void Graphs::solveBandsize(int maxIterations) {
  srand(static_cast<unsigned int>(time(0)));

  // Genera una solucion o etiquetado aleatorio para comenzar a
  // buscar en el vecindario

  std::vector<int> currentSolution = generateRandomSolution();
  std::vector<int> newSolution = currentSolution;
  int bestBandsize = calculateBandsize(currentSolution);
  bestSolution = currentSolution;

  bool stopFlag = false;

  // El bucle terminara hasta que se llegue al numero maximo de iteraciones
  // o que no se encuentre una mejor opcion en el vecindario local
  
  for (int iter = 0; iter < maxIterations && stopFlag == false; ++iter) {
    newSolution = bestSolution;
    currentSolution = bestSolution;

    stopFlag = true;

    // Busca en el vecindario y calcula su bandsize

    for (int u = 0; u < numNodes; u++) {
      for (int v = u + 1; v < numNodes; v++) {

        std::swap(newSolution[u], newSolution[v]);

        int newBandsize = calculateBandsize(newSolution);

        if (newBandsize < bestBandsize) {
          bestBandsize = newBandsize;
          bestSolution = newSolution;
          stopFlag = false;
        }
        newSolution = currentSolution;
      }
    }
  }

  // Imprimir el resultado final
  std::cout << "Costo de la mejor solución encontrada: " << bestBandsize
            << std::endl;
  std::cout << "Etiquetado del grafo producido: ";
  for (int label : bestSolution) {
    std::cout << label + 1 << " "; // Convertir a etiquetas de uno-basado
  }
  std::cout << std::endl;
}

///////////////////////////////////

// La funcion por default solo tiene una complejidad de O(n) donde
// n es el numero de nodos pues genera un solucion o etiquetados
// de los nodos

std::vector<int> Graphs::generateRandomSolution() {
  std::vector<int> solution(numNodes);
  for (int i = 0; i < numNodes; i++) {
    solution[i] = i;
  }
  std::random_shuffle(solution.begin(), solution.end());
  return solution;
}

//////////////////////////////////////

// La funcion hace un recorrido de las aristas de los nodos
// por lo que en el peor de los casos podemos inferir que es una
// complejidad de O(n^2) donde n representa la cantidad de nodos que hay

int Graphs::calculateBandsize(const std::vector<int> &labels) {
  int bandsize = 0;
  int restAbs = 0;
  std::vector<bool> listAbs(numNodes);
  for (int u = 0; u < numNodes; u++) {
    for (int v : adjListGraph[u]) {
      restAbs = abs(labels[u] - labels[v]);
      if (listAbs[restAbs - 1] == false) {
        listAbs[restAbs - 1] = true;
        bandsize++;
      }
    }
  }
  return bandsize;
}

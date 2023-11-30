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



void Graphs::solveBandsize() {

    std::random_device rd;
    std::mt19937 g(rd());

    //Solucion Inicial
    std::vector<int> listaActual = generateRandomSolution();
    std::vector<int> listaSolucion = listaActual;
    int solucion = calculateBandsize(listaSolucion);

    std::vector<int> neoListaSolucion;
    int neoSolucion;

    int delta;

    //Temperatura y sus caracteristicas
    float T = 100;
    float Tf = 0.01;
    float Cooling = 0.98;
    int cl = numNodes * 0.8;

    std::uniform_real_distribution<float> uValue(0.0f, 1.0f);

    while (T > Tf) {
        std::cout << "temp: " << T << " Mejor Solcion:  " << solucion << std::endl;
        int c = 0;
        while (c < cl){
            c++;
            neoListaSolucion = listaActual;
            randomSwap(neoListaSolucion);
            neoSolucion = calculateBandsize(neoListaSolucion);
            delta = neoSolucion - calculateBandsize(listaActual);
            int u = uValue(g);
            if (delta <= 0 or exp(-delta/T) > u) {
                listaActual = neoListaSolucion;
                if (neoSolucion < solucion) {
                    listaSolucion = listaActual;
                    solucion = neoSolucion;
                }
            }
        }
        T = T * Cooling;
    }

    std::cout << "bandsize: " << solucion << std::endl;
    std::cout << "Etiquetado del grafo producido: ";
    for (int label : listaSolucion) {
        std::cout << label + 1 << " "; // Convertir a etiquetas de uno-basado
    }
    std::cout << std::endl;


}

///////////////////////////////////

std::vector<int> Graphs::generateRandomSolution() {
  std::vector<int> solution(numNodes);

  std::random_device rd;
  std::mt19937 g(rd());

  for (int i = 0; i < numNodes; i++) {
    solution[i] = i;
  }
  std::shuffle(solution.begin(), solution.end(), g);
  return solution;
}

///////////////////////////////////////

void Graphs::randomSwap(std::vector<int> &labels) {

    std::random_device rd;
    std::mt19937 g(rd());

    std::uniform_int_distribution<int> randomNode(0, numNodes-1);

    int u = randomNode(g);
    int v;
    do {
        v = randomNode(g);
    }
    while (u == v);

    std::swap(labels[u],labels[v]);

}

//////////////////////////////////////



//No cambiar
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

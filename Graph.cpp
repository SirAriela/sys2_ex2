// 206862666
// ariela

#include "Graph.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace ariel {
enum Answer { ZERO, ONE };
// contrauctor
Graph::Graph() {}
int Graph::getData(size_t i, size_t j) { return this->g[i][j]; }

void Graph::setData(size_t i, size_t j, int change) { this->g[i][j] = change; }

void Graph::loadGraph(vector<vector<int>> graph) {
  try {
    int count = 0;
    bool isSquare = true;
    for (const auto &row : graph) {
      if (row.size() != graph.size()) {
        isSquare = false;
      }
    }
    if (isSquare == true) {
      this->g = graph;
      this->size = graph.size();

      int directed = isDirected();
      setDirected(directed);

      for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
          if (g[i][j] != 0)
            count++;
        }
      }

      this->edges = count;
    } else {
      throw runtime_error("Input is not a valid n*n matrix.");
    }
  }

  catch (const exception &e) {
    cerr << e.what() << endl;
  }
}

string Graph::printGraph() {
  string output = "";
  for (size_t i = 0; i < this->size; i++) {
    output += "[";
    for (size_t j = 0; j < this->size - 1; j++) {
      output += to_string(getData(i, j)) + " , ";
    }
    output += to_string(getData(i, size - 1)) + "]," + "\n";
  }
  return output;
}
void Graph::setDirected(int change) { this->is_directed = change; }

int Graph::isDirected() {
  for (unsigned int i = 0; i < size; i++) {
    for (unsigned int j = 0; j < size; j++) {
      if (this->g[i][j] != this->g[j][i])
        return ONE;
    }
  }
  return ZERO;
}

int Graph::getDirected() { return this->is_directed; }

void Graph::setConnected(int change) { this->is_connected = change; }
int Graph::getConnected() { return this->is_connected; }

void Graph::setSize(int change) { this->size = (unsigned)change; }
size_t Graph::getSize() { return this->size; }

// ------------------ overloading methods
// ----------------------------------------------------------

Graph Graph::operator+(const Graph &other) {
  vector<vector<int>> g(this->size, vector<int>(this->size, 0));
  if (this->size == other.size) {
    for (size_t i = 0; i < this->size; i++) {
      for (size_t j = 0; j < this->size; j++) {
        g[i][j] = this->g[i][j] + other.g[i][j];
      }
    }
    ariel::Graph k;
    k.loadGraph(g);

    return k;
  } else
    throw "the graphs has different sizes";
}

Graph &Graph::operator+=(const Graph &other) {
  if (this->size == other.size) {
    for (size_t i = 0; i < this->size; i++) {
      for (size_t j = 0; j < this->size; j++) {
        this->g[i][j] = this->g[i][j] + other.g[i][j];
      }
    }
    return (*this);
  } else
    throw "the graphs has different sizes";
}

Graph Graph::operator+() { return *this; }

Graph Graph::operator-(const Graph &other) {
  vector<vector<int>> g(this->size, vector<int>(this->size, 0));
  if (this->size == other.size) {
    for (size_t i = 0; i < this->size; i++) {
      for (size_t j = 0; j < this->size; j++) {
        g[i][j] = this->g[i][j] - other.g[i][j];
      }
    }
    ariel::Graph k;
    k.loadGraph(g);

    return k;
  } else
    throw "the graphs has different sizes";
}

Graph &Graph::operator-=(const Graph &other) {
  if (this->size == other.size) {
    for (size_t i = 0; i < this->size; i++) {
      for (size_t j = 0; j < this->size; j++) {
        this->g[i][j] = this->g[i][j] - other.g[i][j];
      }
    }
    return (*this);
  } else
    throw "the graphs has different sizes";
}

Graph &Graph::operator-() {
  for (size_t i = 0; i < this->size; i++) {
    for (size_t j = 0; j < this->size; j++) {
      this->g[i][j] = this->g[i][j] * (-1);
    }
  }
  return *this;
}

Graph &Graph::operator*=(const int number) {

  for (size_t i = 0; i < this->size; i++) {
    for (size_t j = 0; j < this->size; j++) {
      this->g[i][j] = this->g[i][j] * number;
    }
  }
  return (*this);
}
std::ostream &operator<<(std::ostream &os, const Graph &graph) {
  for (size_t i = 0; i < graph.size; i++) {
    os << "[";
    for (size_t j = 0; j < graph.size - 1; j++) {
      os << to_string(graph.g[i][j]) + " , ";
    }
    os << to_string(graph.g[i][graph.size - 1]) + "]," << endl;
  }
  return os;
}

Graph &Graph::operator++(int) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (getData(i, j) != 0) {
        ++g[i][j];
      }
    }
  }
  return *this;
}

Graph &Graph::operator++() {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (getData(i, j) != 0) {
        ++g[i][j];
      }
    }
  }
  return *this;
}

bool Graph::operator==(const Graph &other) const {
  bool same_data = true;
  bool same_size = true;
  bool smallequal;

  if (this->size == other.size) {
    same_size = false;
  }
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (this->g[i][j] != other.g[i][j]) {
        same_data = false;
      }
    }
  }
  smallequal = !(*this < other) || !(*this > other);

  return (same_data && same_size) || smallequal;
}

bool Graph::operator<=(const Graph &other) const {
  if (*this < other || *this == other)
    return true;
  return false;
}

bool Graph::operator>=(const Graph &other) const {
  if (other <= *this)
    return true;
  return false;
}

bool Graph::operator<(const Graph &other) const {
  bool g1IsSubGraph = true;

  if (this->size > other.size)
    return false;

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (g[i][j] != 0 && other.g[i][j] == 0) {
        g1IsSubGraph = false;
        break;
      }
    }
    if (!g1IsSubGraph) {
      break;
    }
  }

  if (g1IsSubGraph)
    return true;

  if (this->edges > other.edges)
    return false;

  return true;
}

// if g1 > g2 => if g2 is a subgraph of g1
bool Graph::operator>(const Graph &other) const {
  if (other < *this)
    return true;
  return false;
}

// if g1 != g2
bool Graph::operator!=(const Graph &other) const {
  if (!(*this == other))
    return true;
  return false;
}

Graph Graph::operator*(const Graph &other) {
  if (this->size != other.size) {
    throw std::invalid_argument(
        "Graphs must be of the same size for multiplication.");
  }
  size_t n = this->size;
  vector<vector<int>> newGraph(n, vector<int>(n, 0));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        newGraph[i][j] += this->g[i][k] * other.g[k][j];
      }
    }
  }

  ariel::Graph k;
  k.loadGraph(newGraph);

  return k;
}
} // namespace ariel

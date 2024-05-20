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

void Graph::loadGraph(vector<vector<int>> graph) {
  try {
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
    } else {
      throw runtime_error("Input is not a valid n*n matrix.");
    }
  }

  catch (const exception &e) {
    cerr << e.what() << endl;
  }
}

void Graph::printGraph() {
  for (size_t i = 0; i < this->size; i++) {
    cout << "[";
    for (size_t j = 0; j < this->size - 1; j++) {
      cout << to_string(getData(i, j)) + " , ";
    }
    cout << to_string(getData(i, size - 1)) + "]," << endl;
  }
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
    os << to_string(graph.g[i][graph.size-1]) + "]," << endl;
  }
  return os;
}

} // namespace ariel

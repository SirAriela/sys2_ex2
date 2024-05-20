// 206862666
// ariela

#pragma once

#include <cstddef>
#include <ostream>
#include <vector>
using namespace std;

namespace ariel {
class Graph {
  vector<vector<int>> g; // the graph
  int is_connected;      // 1 - is connected, 0 - otherwise
  int is_directed;       // 1 - is directed, 0 - otherwise
  size_t size;           // the size of vector
  int edges;             // number of edges in the graph
public:
  // Constructor
  Graph();

  // Function to load graph from adjacency matrix
  void loadGraph(vector<vector<int>> graph);

  // Function to print graph
  void printGraph();

  // if directed return 1, otherwise 0
  int isDirected();

  // getters and setters for contributes
  void setDirected(int change);
  int getDirected();

  // returns the weight of an edge, if there is none returns ZERO
  int getData(size_t i, size_t j);

  void setConnected(int change);
  int getConnected();

  void setSize(int change);
  size_t getSize();

  // ------------------ overloading methods ------------------

  // returns new graph with g1 + g2 values
  Graph operator+(const Graph &other);
  // takes the left graph and add to him the right graph
  Graph &operator+=(const Graph &other);
  // basicly does nothing.. supoues to multiply by 1 all the graph edges
  Graph operator+();
  // returns new graph with g1 - g2 values
  Graph operator-(const Graph &other);
  // takes the left graph and subtract to him with the right graph values
  Graph &operator-=(const Graph &other);
  // multiply the graph edges by -1
  Graph &operator-();
  // multiply a graph by an integer
  Graph &operator*=(const int number);

  //replaces the cout operation
   friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
};
} // namespace ariel

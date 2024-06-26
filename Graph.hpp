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
  string printGraph();
  

  // if directed return 1, otherwise 0
  int isDirected();

  // getters and setters for contributes
  void setDirected(int change);
  int getDirected();

  // returns the weight of an edge, if there is none returns ZERO
  int getData(size_t i, size_t j);
  void setData(size_t i, size_t j,int change);

  void setConnected(int change);
  int getConnected();

  void setSize(int change);
  size_t getSize();

  // ------------------ overloading methods  EX 2 ------------------

  // calculating operators -----------------------------------

  //  returns new graph with g1 + g2 values
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

  // replaces the cout operation
  friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

  // increess by one postfix
  Graph &operator++(int);

  // increess by one prefix
  Graph &operator++();

  // comparison operators -------------------------------

  // if g1 and g2 is equal or (g1 <= g2)and(g2<=g1)
  bool operator==(const Graph &other)const;

  // if g1 <= g2 return true
  bool operator<=(const Graph &other)const;
  // if g1 >= g2 return true
  bool operator>=(const Graph &other)const;

  // if g1 < g2 => if g1 is a subgraph of g2
  bool operator<(const Graph &other)const;

  // if g1 > g2 => if g2 is a subgraph of g1
  bool operator>(const Graph &other)const;

  //if g1 != g2
  bool operator!=(const Graph &other)const;

  //matrix mult ,creates new graph
  Graph operator*(const Graph &other);

};
} // namespace ariel

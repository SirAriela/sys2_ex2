/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
// 206862666
// ariela

#include "Algorithms.hpp"
#include "Graph.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace ariel::Algorithms;

int main() {
  ariel::Graph g;
  // 3x3 matrix that represents a connected graph.
  vector<vector<int>> graph1 = {
      {0, 5, 0, 0, 0}, {0, 0, 0, 0, 5}, {5, 0, 0, 0, 0},
      {0, 5, 5, 0, 0}, {0, 0, 0, 5, 0},

  };
  g.loadGraph(graph1); // Load the graph to the object.

  g.printGraph(); // Should print: "Graph with 5 vertices and 6 edges."
  cout << Algorithm::isConnected(g) << endl; // Should print: "0" (false).
  cout << Algorithm::shortestPath(g, 3, 4) << endl; // Should print: 3-> 1 -> 4
  cout << Algorithm::isContainsCycle(g) << endl;    // Should print: the cycle
  cout << Algorithm::isBipartite(g) << endl; // Should print: is not biratate
  // 5x5 matrix that represents a non-connected graph with a cycle.
  vector<vector<int>> graph2 = {
      {0, 0, 0, 0, 0, -3}, {0, 0, 0, 5, 0, 0},  {0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, -3, 0}, {0, -3, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
  };

  g.loadGraph(graph2); // Load the graph to the object.

  g.printGraph(); // Should print: "Graph with 5 vertices and 8 edges."
  cout << Algorithm::isConnected(g) << endl; // Should print: "0" (false).
  cout << Algorithm::shortestPath(g, 0, 4)
       << endl; // Should print: "-1" (there is no path between 0 and 4).
  cout << Algorithm::isContainsCycle(g)
       << endl;                              // Should print: "negetive cycle"
  cout << Algorithm::isBipartite(g) << endl; // Should

  // 5x5 matrix that reprsents a connected weighted graph.
  vector<vector<int>> graph3 = {
      {0, 0, 0, 2, 5, 0},
       {0, 0, 0, 0, 0, -3}
       , {0, 0, 0, 0, 2, 0},
      {2, 0, 0, 0, 0, 1}, 
      {5, 0, 2, 0, 0, 0}, 
       {0, -3, 0, 1, 0, 0},

  };
  try {
    g.loadGraph(graph3); // Load the graph to the object.
    g.printGraph();      // Should print: "Graph with 6 vertices and 5 edges."
    cout << ariel::Algorithms::Algorithm::isConnected(g)
         << endl; // Should print: "0" (true).
    cout << ariel::Algorithms::Algorithm::negativeCycle(g) << endl;
    cout << ariel::Algorithms::Algorithm::shortestPath(g, 0, 3)
         << endl; // Should print: 0->2->3->4.
    cout << ariel::Algorithms::Algorithm::isContainsCycle(g)
         << endl; // Should print: "0" (false).
    cout << ariel::Algorithms::Algorithm::isBipartite(g)
         << endl; // Should print: "The graph is bipartite: A={0, 2, 4}, B={1,
                  // 3}."

  } catch (const std::invalid_argument &e) {
    cout << e.what() << endl; // Should print: "Invalid graph: The graph is not
                              // a square matrix."
  }

  // 5x4 matrix that reprsents invalid graph.
  vector<vector<int>> graph4 = {
      {0, 7, 0, -3, 0, -2}, 
      {7, 0, 1, 0, 0, 0}, 
      {0, 1, 0, 3, 0, 4},
      {-3, 0, 3, 0, 0, 0}, 
       {0, 0, 0, 0, 0, 1},
        {-2, 0, 4, 0, 1, 0},
  };
  try {
    g.loadGraph(graph4); // Load the graph to the object.
    g.printGraph();      // Should print: "Graph with 6 vertices and 5 edges."
    cout << ariel::Algorithms::Algorithm::isConnected(g)
         << endl; // Should print: "0" (true).
    cout << ariel::Algorithms::Algorithm::negativeCycle(g) << endl;
    cout << ariel::Algorithms::Algorithm::shortestPath(g, 5, 2)
         << endl; // Should print: 0->2->3->4.
    cout << ariel::Algorithms::Algorithm::isContainsCycle(g)
         << endl; // Should print: "0" (false).
    cout << ariel::Algorithms::Algorithm::isBipartite(g)
         << endl; // Should print: "The graph is bipartite: A={0, 2, 4}, B={1,
                  // 3}."

  } catch (const std::invalid_argument &e) {
    cout << e.what() << endl; // Should print: "Invalid graph: The graph is not
                              // a square matrix."
  }

  try {
    ariel::Graph g1;
    g1.loadGraph(graph3);
    g.printGraph();
    cout << "-----------------" << endl;
    g1.printGraph();
    cout << "-----------------" << endl;
    g += g1;
    cout << g;
    g++;
    ++g;
    cout << g;
    if (g1 > g1)
      cout << "g1 is g1" << endl;

    cout << "------------------------------------" << endl;
    ariel::Graph G3;
    G3 = g1 * g;
    cout << G3;

  } catch (const std::invalid_argument &e) {
    cout << e.what() << endl; // Should print: "Invalid graph: The graph is
                              // not a square matrix."
  }
}

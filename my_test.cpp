// 206862666
// ariela
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "doctest.h"
#include <vector>

using namespace std;
using namespace ariel::Algorithms;

TEST_CASE("Test isConnected") {
  ariel::Graph g;
  vector<vector<int>> graph1 = {
      {0, 1, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0},
      {1, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0},

  };
  g.loadGraph(graph1);

  CHECK(Algorithm::isConnected(g) == true);

  vector<vector<int>> graph2 = {
      {0, 0, 0, 0, 0, 3}, {0, 0, 0, 0, 3, 0}, {0, 5, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 1}, {7, 0, 5, 0, 0, 0}, {0, 0, 0, 0, 1, 0},
  };
  g.loadGraph(graph2);
  CHECK(Algorithm::isConnected(g) == true);

  vector<vector<int>> graph3 = {
      {0, 0, 0, 0, 0}, {0, 0, 0, 0, 3}, {0, 5, 0, 1, 0},
      {0, 0, 0, 0, 0}, {7, 0, 5, 0, 0},
  };
  g.loadGraph(graph3);
  CHECK(Algorithm::isConnected(g) == false);
}

TEST_CASE("contains negetive cycle") {
  ariel::Graph g;

  vector<vector<int>> graph5 = {
      {0, 5, 0, 0, 0, 0},  {0, 0, 7, 0, 0, 1}, {0, 0, 0, 0, -6, 0},
      {0, -4, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 3, 0, 0, 0},
  };
  g.loadGraph(graph5);
  CHECK(Algorithm::negativeCycle(g) == "there is a negetive cycle");

  vector<vector<int>> graph6 = {
      {0, 5, 0, 0, 0, 0},  {0, 0, 7, 0, 0, 1}, {0, 0, 0, 0, -6, 0},
      {0, -4, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 3, 0, 0, 0},
  };
  g.loadGraph(graph6);
  CHECK(Algorithm::negativeCycle(g) == "there is a negetive cycle");

  vector<vector<int>> graph2 = {
      {0, 3, 0, 0, 0},   {0, 0, 1, 0, 0},  {-2, 0, 0, 11, 0},
      {11, 0, 0, 0, -2}, {0, 0, -2, 0, 0},
  };

  g.loadGraph(graph2);
  CHECK(Algorithm::negativeCycle(g) == "there is no negetive cycle");
}

TEST_CASE("has a cycle") {
  ariel::Graph g;

  vector<vector<int>> graph5 = {
      {0, 5, 0, 0, 0, 0},  {0, 0, 7, 0, 0, 1}, {0, 0, 0, 0, -6, 0},
      {0, -4, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, -11, 0, 0, 0},
  };
  g.loadGraph(graph5);
  CHECK(Algorithm::isContainsCycle(g) == "there is a negetive cycle");

  vector<vector<int>> graph6 = {
      {0, 5, 0, 0, 0, 0},  {0, 0, 7, 0, 0, 1}, {0, 0, 0, 0, -6, 0},
      {0, -4, 0, 0, 0, 0}, {0, 0, 0, 7, 0, 0}, {0, 0, 3, 0, 0, 0},
  };
  g.loadGraph(graph6);
  CHECK(Algorithm::isContainsCycle(g) == "1->3->4->2->1");

  vector<vector<int>> graph2 = {
      {0, 0, 0, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0}, {0, 1, 0, 0, 0},

  };

  g.loadGraph(graph2);
  CHECK(Algorithm::isContainsCycle(g) == "there is a negetive cycle");
}

TEST_CASE("is bipartite") {
  ariel::Graph g;
  vector<vector<int>> birpatite = {
      {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0},

  };
  g.loadGraph(birpatite);
  CHECK(Algorithm::isBipartite(g) == "A = {0, 1, 5, } B = {2, 3, 4, }");

  vector<vector<int>> isnotbipartite = {
      {0, 1, 0, 0, 7}, {1, 0, 7, 7, 0}, {0, 7, 0, 1, 7},
      {0, 7, 1, 0, 7}, {7, 0, 7, 7, 0},

  };
  g.loadGraph(isnotbipartite);
  CHECK(Algorithm::isBipartite(g) == "is not bipartite");

  vector<vector<int>> graph4 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g.loadGraph(graph4);
  CHECK(Algorithm::isBipartite(g) == "is not bipartite");
}

TEST_CASE("shortest path ") {
  ariel::Graph g;
  vector<vector<int>> graph2 = {{0, 1, 1, 0, 0},
                                {1, 0, 1, 0, 0},
                                {1, 1, 0, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}};

  g.loadGraph(graph2);
  CHECK(Algorithm::shortestPath(g, 0, 2) == "0->2");

  vector<vector<int>> graph3 = {
      {0, 5, 1},
      {5, 0, 1},
      {1, 1, 0},

  };
  g.loadGraph(graph3);
  CHECK(Algorithm::shortestPath(g, 0, 1) == "0->2->1");

  vector<vector<int>> graph4 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g.loadGraph(graph4);
  CHECK(Algorithm::shortestPath(g, 0, 4) == "0->3->4");
}

TEST_CASE("+ , - ") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);

  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);

  CHECK_THROWS(g2 + g1);

  vector<vector<int>> graph3 = {{0, 1, 0, 0, 1},
                                {1, 0, 1, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 0, 1, 0}};
  g3.loadGraph(graph3);

  g4 = g3 + g1;
  CHECK(g4.printGraph() == (g1 + g3).printGraph());

  CHECK_THROWS(g2 - g1);
  g4 = g3 - g1;
  CHECK(g4.printGraph() == (g3 - g1).printGraph());
}

TEST_CASE("+= , -=") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);

  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);

  CHECK_THROWS(g2 += g1);
  CHECK_THROWS(g2 -= g1);
  vector<vector<int>> graph3 = {{0, 1, 0, 0, 1},
                                {1, 0, 1, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 0, 1, 0}};
  g3.loadGraph(graph3);
  g4.loadGraph(graph3);
  g3 += g1;

  CHECK(g3.printGraph() == (g4 + g1).printGraph());
  g3 -= g1;
  CHECK(g3.printGraph() == g4.printGraph());
}

TEST_CASE("* by graph") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);

  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);

  CHECK_THROWS(g2 * g1);
  vector<vector<int>> graph3 = {{0, 1, 0, 0, 1},
                                {1, 0, 1, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 0, 1, 0}};
  g3.loadGraph(graph3);
  g4.loadGraph(graph3);

  g3 = g3 * g1;
  CHECK(g3.printGraph() ==
        "[0 , 0 , 0 , 0 , 2],\n[0 , 8 , 1 , 2 , 10],\n[0 , 0 , 0 , 0 , 3],\n[0 "
        ", 3 , 0 , 0 , 0],\n[0 , 5 , 1 , 2 , 11],\n");
}

TEST_CASE("* by number") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);
  g3.loadGraph(graph1);
  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);
  g4.loadGraph(graph2);

  g1 *= 3;
  g2 *= 8;

  for (size_t i = 0; i < g3.getSize(); i++) {
    for (size_t j = 0; j < g3.getSize(); j++) {
      int data = g3.getData(i, j) * 3;
      g3.setData(i, j, data);
    }
  }

  for (size_t i = 0; i < g4.getSize(); i++) {
    for (size_t j = 0; j < g4.getSize(); j++) {
      int data = g4.getData(i, j) * 8;
      g4.setData(i, j, data);
    }
  }

  CHECK(g1.printGraph() == g3.printGraph());
  CHECK(g2.printGraph() == g4.printGraph());
}

TEST_CASE("== / !=") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);
  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);

  bool check1 = graph1 == graph2;
  bool check2 = graph1 != graph2;
  CHECK(check1 == false);
  CHECK(check2 == true);
}

TEST_CASE("< / >") {
  ariel::Graph g1;
  ariel::Graph g2;
  ariel::Graph g3;
  ariel::Graph g4;

  vector<vector<int>> graph1 = {
      {0, 5, 1, 2, 10}, {0, 0, 0, 0, 2}, {0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1},  {0, 0, 0, 0, 0},

  };
  g1.loadGraph(graph1);
  vector<vector<int>> graph2 = {{0, 1, 1, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}};

  g2.loadGraph(graph2);

  bool check1 = graph1 < graph2;
  bool check2 = graph1 > graph2;
  CHECK(check1 == false);
  CHECK(check2 == true);
}
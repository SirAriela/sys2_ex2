//206862666
//ariela
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ariel::Graph g;

  vector<vector<int>> graph5 = {
      {0, 5, 0, 0, 0, 0},  
      {0, 0, 7, 0, 0, 1}, 
      {0, 0, 0, 0, -6, 0},
      {0, -4, 0, 0, 0, 0}, 
      {0, 0, 0, 1, 0, 0},
       {0, 0, 3, 0, 0, 0},
  };

  vector<vector<int>> graph1 = {
      {0, 0, 0, 0}, 
{0, 0, 0, 1}, 
{0, 0, 0, 1}, 
{1, 0, 0, 0}, 


  };
  vector<vector<int>> graph2 = {{0, 1, 1, 0, 0},
                                {1, 0, 1, 0, 0},
                                {1, 1, 0, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}};

  vector<vector<int>> hasCycle = {
      {0, 0, 0, 3, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 3},
      {0, 1, 0, 0, 7, 0}, {0, 0, 3, 0, 0, 0}, {0, 7, 0, 0, 0, 0},

  };
  vector<vector<int>> birpatite = {
{0, 0, 1, 0, 0, 0}, 
{0, 0, 0, 1, 1, 0}, 
{0, 1, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 1}, 
{0, 1, 0, 0, 0, 0}, 
{0, 0, 1, 0, 0, 0}, 

  };
  vector<vector<int>> graph6 = {
{0, 0, 0, 0, 7}, 
{0, 0, 7, 7, 0}, 
{0, 7, 0, 0, 7}, 
{0, 7, 0, 0, 7}, 
{7, 0, 7, 7, 0}, 

  };
  // g.loadGraph(graph2);
  // g.loadGraph(graph1);
  g.loadGraph(birpatite);
  string x = ariel::Algorithms::Algorithm::isBipartite(g);
  cout << x << endl;
}

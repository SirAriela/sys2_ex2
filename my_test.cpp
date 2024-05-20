//206862666
//ariela
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
    {0, 5, 0, 0, 0, 0},  
    {0, 0, 7, 0, 0, 1}, 
    {0, 0, 0, 0, -6, 0},
    {0, -4, 0, 0, 0, 0}, 
    {0, 0, 0, 1, 0, 0}, 
    {0, 0, -11, 0, 0, 0},
  };
  g.loadGraph(graph5);
  CHECK(Algorithm::isContainsCycle(g) == "there is a negetive cycle");

  vector<vector<int>> graph6 = {
{0, 5, 0, 0, 0, 0}, 
{0, 0, 7, 0, 0, 1}, 
{0, 0, 0, 0, -6, 0}, 
{0, -4, 0, 0, 0, 0}, 
{0, 0, 0, 7, 0, 0}, 
{0, 0, 3, 0, 0, 0}, 
};
  g.loadGraph(graph6);
  CHECK(Algorithm::isContainsCycle(g) == "1->3->4->2->1");

  vector<vector<int>> graph2 = {
{0, 0, 0, 0, 0}, 
{1, 0, 0, 1, 0}, 
{1, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0}, 
{0, 1, 0, 0, 0}, 

  };

  g.loadGraph(graph2);
  CHECK(Algorithm::isContainsCycle(g) == "no cycle");
}


TEST_CASE("is bipartite"){
  ariel::Graph g;
  vector<vector<int>> birpatite = {
{0, 0, 1, 0, 0, 0}, 
{0, 0, 0, 1, 1, 0}, 
{0, 1, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 1}, 
{0, 1, 0, 0, 0, 0}, 
{0, 0, 1, 0, 0, 0}, 

  };
  g.loadGraph(birpatite);
  CHECK(Algorithm::isBipartite(g) == "A = {0, 1, 5, } B = {2, 3, 4, }");

   vector<vector<int>> isnotbipartite = {
{0, 1, 0, 0, 7}, 
{1, 0, 7, 7, 0}, 
{0, 7, 0, 1, 7}, 
{0, 7, 1, 0, 7}, 
{7, 0, 7, 7, 0}, 

  };
 g.loadGraph(isnotbipartite);
  CHECK(Algorithm::isBipartite(g) == "is not bipartite");


  vector<vector<int>> graph4={
    {0, 5, 1, 2, 10}, 
{0, 0, 0, 0, 2}, 
{0, 3, 0, 0, 0}, 
{0, 0, 0, 0, 1}, 
{0, 0, 0, 0, 0}, 

  };
   g.loadGraph(graph4);
  CHECK(Algorithm::isBipartite(g) == "is not bipartite");


}

TEST_CASE("shortest path "){
  ariel::Graph g;
  vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); 
    CHECK(Algorithm::shortestPath(g,0, 2) == "2<-0");

vector<vector<int>> graph3 ={
{0, 5, 1}, 
{5, 0, 1}, 
{1, 1, 0}, 

};
g.loadGraph(graph3);
  CHECK(Algorithm::shortestPath(g,0, 1) == "1<-2<-0");

  vector<vector<int>> graph4={
    {0, 5, 1, 2, 10}, 
{0, 0, 0, 0, 2}, 
{0, 3, 0, 0, 0}, 
{0, 0, 0, 0, 1}, 
{0, 0, 0, 0, 0}, 

  };
  g.loadGraph(graph4);
  CHECK(Algorithm::shortestPath(g,0, 4) == "4<-3<-0");

}
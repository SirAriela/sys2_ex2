//206862666
//ariela
#include "Graph.hpp"
#include <cstddef>
#include <queue>
#include <string>
#include <vector>

namespace ariel
{
    namespace Algorithms {
        class Algorithm {
            public:
                //will check if graph is connected ONE- if connected ZERO otherwise
                //will use bfs algorithem to check if the graph is connected
                static int isConnected(Graph& g);

                //bfs algo, returns vector<bool> with visited/unvisited vertexes
                static vector<bool> BFS(Graph& g, int start);

                //dfs algorithm checks all v in adj matrix and 
                //returns if there is a cycle
                static size_t DFSvisit(Graph& g, size_t u, vector<bool> &visited,vector<size_t> &parent , queue<size_t> &dfsStack);

                //finds shortest path from one vertex to another
                //will use BF and/or dijikstra to find it
                static std::string shortestPath(Graph &g, size_t start, size_t end);

                //finds if there is a cycle in a graph
                //returns the cycle otherwise 0
                //will use DFS algorithm
                static string isContainsCycle(Graph& g);

                //finds if the graph is bipartite
                //returns the haluka, ZERO otherwise
                static string isBipartite(Graph& g);

                //finds if the graph has negetive cycles
                //returns the cycle, ZERO otherwise
                //will use BF
                static string negativeCycle(Graph& g);
        };
    }
}

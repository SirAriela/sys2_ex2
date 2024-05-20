// 206862666
// ariela
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <linux/limits.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
enum Answer { ZERO, ONE };
const size_t negetive = static_cast<size_t>(-1);

namespace ariel {
namespace Algorithms {

vector<bool> Algorithm::BFS(Graph &g, int start_index) {
  // vars
  size_t start = static_cast<size_t>(start_index);
  int sizeOfGraph = g.getSize();
  vector<bool> visited((size_t)sizeOfGraph, false);
  queue<size_t> q;

  // add first vertex into q and mark it true
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    // check the top vertex neighbors
    size_t current = q.front();
    q.pop();
    for (size_t i = 0; i < sizeOfGraph; i++) {
      // dont need to check it with himself
      if (i != current) {
        int x = g.getData(current, i);
        // check if neighbor is alredy visited
        if (x != ZERO) {
          if (!visited[i]) {
            // if not visited yet, marks as visited and add him to queue
            visited[i] = true;
            q.push(i);
          }
        }
      }
    }
  }

  return visited;
}
// using BFS checking if a graph is connected or not
int Algorithm::isConnected(Graph &g) {
  for (int i = 0; i < g.getSize(); i++) {
    vector<bool> checkIfAllVisited = BFS(g, i);
    for (unsigned int j = 0; j < g.getSize(); j++) {
      if (!checkIfAllVisited[j])
        return ZERO;
    }
  }
  return ONE;
}

string Algorithm::shortestPath(Graph &g, size_t start, size_t end) {
  // Check for negative cycle
  if (Algorithm::negativeCycle(g).compare("there is a negetive cycle") == 0) {
    return "no shortest path";
  } else {
    size_t size = g.getSize();

    vector<int> distance(
        size, MAX_INPUT); // Initialize distances with maximum input value
    vector<int> predecessor(size, -1); // Initialize predecessor array with -1

    distance[start] = 0;        // Distance to start vertex is 0
    predecessor[start] = start; // Predecessor of start vertex is itself
    string path = "";
    size_t n = size - 1;

    // size - 1 times
    for (size_t i = 0; i < n; i++) {
      // for all vertexes
      for (size_t curretnt = 0; curretnt < size; curretnt++) {
        // check neighbor for each neighbor
        for (size_t j = 0; j < size; j++) {
          if (curretnt != j) {
            int weight = g.getData(curretnt, j);
            int distanceStart = distance[curretnt];
            int distanceNext = distance[j];

            // relax
            if ((weight + distanceStart < distanceNext) && weight != 0 &&
                distanceStart != MAX_INPUT) {
              distance[j] = weight + distanceStart;
              if (predecessor[curretnt] != j)
                predecessor[j] = curretnt;
            }
          }
        }
      }
    }

    if (distance[end] < MAX_INPUT) {
      stack<int> s;
      s.push(end);
      while (predecessor[end] != start) {
        s.push(predecessor[end]);

        end = (size_t)predecessor[end];
      }

      s.push(start);
      path += to_string(s.top());
      s.pop();

      int x;
      while (!s.empty()) {
        x = s.top();
        path += "->" + to_string(x);
        s.pop();
      }

      return path;
    }
    return "no path";
  }
}

size_t Algorithm::DFSvisit(Graph &g, size_t u, vector<bool> &visited,
                           vector<size_t> &parent, queue<size_t> &dfsStack) {
  visited[u] = true;
  dfsStack.push(u);
  size_t size = g.getSize();

  for (size_t v = 0; v < size; v++) {
    if (g.getData(u, v) != ZERO) {
      if (!visited[v]) {
        parent[v] = u;
        return DFSvisit(g, v, visited, parent, dfsStack);
      } else if (visited[v] && parent[u] != v) {
        parent[v] = u;
        return v;
      }
    }
  }

  return SIZE_MAX;
}

void emptyStack(queue<size_t> &s) {
  while (!s.empty())
    s.pop();
}
void resetParentAndVisited(vector<size_t> &parent, vector<bool> &visited) {
  for (size_t i = 0; i < visited.size(); i++) {
    parent[i] = negetive;
    visited[i] = false;
  }
}

string Algorithm::isContainsCycle(Graph &g) {
  if (Algorithm::negativeCycle(g).compare("there is a negetive cycle") == 0) {
    return "there is a negetive cycle";
  }

  size_t size = g.getSize();
  vector<size_t> parent(
      size, static_cast<size_t>(-1)); // Initialize parent array with -1
  vector<bool> visited(size, false);
  queue<size_t> s;
  string cycle = "";

  for (size_t u = 0; u < size; u++) {
    if (!visited[u]) {
      size_t x = DFSvisit(g, u, visited, parent, s);
      // there is a cycle
      if (x != SIZE_MAX) {

        cycle += to_string(x) + "->";
        size_t current = x;
        while (parent[current] != x) {
          cycle += to_string(parent[current]) += "->";
          current = parent[current];
        }
        cycle += to_string(x);

        // cycle += to_string(u);
        return cycle;
      }

    } else {
      cycle += to_string(u) + "->";
      size_t current = u;
      while (parent[current] != u) {
        cycle += to_string(parent[current]) += "->";
        current = parent[current];
      }
      cycle += to_string(u);

      // cycle += to_string(u);
      return cycle;
    }

    emptyStack(s);
    resetParentAndVisited(parent, visited);
  }

  return "no cycle";
}

string Algorithm::isBipartite(Graph &g) {
  size_t size = g.getSize();
  vector<bool> visited(size, false);
  vector<int> color(size, -1);
  bool currentColor = true;
  string haluka = "";

  for (size_t u = 0; u < size; u++) {

    if (!visited[u]) {
      visited[u] = true;
      color[u] = currentColor;
      currentColor = !currentColor;
    }

    queue<size_t> q;
    q.push(u);

    while (!q.empty()) {
      size_t current = q.front();
      q.pop();

      for (size_t v = 0; v < size; ++v) {
        if (g.getData(current, v) != 0) {
          if (!visited[v]) { // If v is not visited
            visited[v] = true;
            color[v] = !color[current]; // Assign opposite color to v
            q.push(v);
          } else if (color[v] ==
                     color[current]) { // If v has the same color as current
            return "is not bipartite"; // Violation of bipartite property
          }
        }
      }
    }
  }
  haluka += "A = {";
  for (size_t i = 0; i < size; i++) {
    if (color[i]) {
      haluka += to_string(i) + ", ";
    }
  }
  haluka += "} B = {";
  for (size_t i = 0; i < size; i++) {
    if (!color[i]) {
      haluka += to_string(i) + ", ";
    }
  }
  haluka += "}";

  return haluka;
}

string Algorithm::negativeCycle(Graph &g) {
  size_t sizeOfGraph = g.getSize();
  vector<int> distance(sizeOfGraph, INT_MAX);
  distance[ZERO] = ZERO;
  string negetiveCycle = " ";
  size_t n = sizeOfGraph - 1;

  if (!g.isDirected()) {
    int count = 0;
    for (size_t i = 0; i < sizeOfGraph; i++) {
      // for all vertexes
      for (size_t curretnt = 0; curretnt < sizeOfGraph; curretnt++) {
        count += g.getData(i, curretnt);
      }
    }
    if (count < 0) {
      return "there is a negetive cycle";
    }

    return "there is no negetive cycle";
  }

  // size - 1 times
  for (size_t i = 0; i < sizeOfGraph; i++) {
    // for all vertexes
    for (size_t curretnt = 0; curretnt < sizeOfGraph; curretnt++) {
      // check neighbor for each neighbor
      for (size_t j = 0; j < sizeOfGraph; j++) {
        if (curretnt != j) {
          int weight = g.getData(curretnt, j);
          int distanceStart = distance[curretnt];
          int distanceNext = distance[j];

          // relax
          if ((weight + distanceStart < distanceNext) && weight != 0 &&
              distance[curretnt] != INT_MAX) {
            distance[j] = weight + distanceStart;
          }
        }
      }
    }
  }

  for (size_t curretnt = 0; curretnt < sizeOfGraph; curretnt++) {
    for (size_t j = 0; j < sizeOfGraph; j++) {
      int wieght = g.getData(curretnt, j);
      int distanceCurrent = distance[curretnt];
      int wieghtToNewVertex = distance[j];
      if ((wieght + distanceCurrent < wieghtToNewVertex) && wieght != 0 &&
          curretnt != j) {
        return "there is a negetive cycle";
      }
    }
  }
  return "there is no negetive cycle";
}

} // namespace Algorithms
} // namespace ariel

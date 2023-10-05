#include "queue.hpp"
#include "graph.hpp"

int bfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n;
    bool visited[N] = {false};
    int trace[N] = {-1};
    int numPath[N] = {0};
    
    Queue<int> queue;
    queue.push(start);
    visited[start] = true;
    numPath[start] = 1;
    
    while (!queue.empty()) {
        int u = queue.pop();
        
        if (u == destination) {
            break;
        }
        
        LinkedList<int>& neighbors = G.e[u];
        LinkedListNode<int>* currentNode = neighbors.getRoot();
        while (currentNode) {
            int v = currentNode->value;
            if (!visited[v]) {
                visited[v] = true;
                trace[v] = u;
                numPath[v] = numPath[u] + 1;
                queue.push(v);
            }
            // Remove the else if condition that modifies numPath
            currentNode = currentNode->next;
        }
    }
    
    int u = destination;
    while (u != -1) {
        path.insert(path.begin(), u);
        u = trace[u];
    }
    
    // Count the number of shortest paths
    int shortestPathCount = 0;
    for (int node = 0; node < N; ++node) {
        if (node != start && node != destination && numPath[node] == numPath[destination] - 1) {
            int current = node;
            bool isShortestPath = true;
            while (current != start) {
                if (numPath[current] != numPath[trace[current]] + 1) {
                    isShortestPath = false;
                    break;
                }
                current = trace[current];
            }
            if (isShortestPath) {
                shortestPathCount++;
            }
        }
    }
    
    return shortestPathCount;
}


#include "graph.hpp"

int DFS(int u, Graph &G, std::vector<int> &path, std::vector<int> &visited, int destination, int numberOfBuilding) {
    path.push_back(u);
    visited[u] = 1; // Use 1 to represent visited in the visited vector

    if (u == destination) {
        return 1;
    }

    int neighborsVisited = 0; // Track the number of visited neighbors

    LinkedList<int>& neighbors = G.e[u];
    LinkedListNode<int>* currentNode = neighbors.getRoot();
    while (currentNode && neighborsVisited < numberOfBuilding) {
        int v = currentNode->value;
        if (!visited[v]) {
            int flag = DFS(v, G, path, visited, destination, numberOfBuilding);
            if (flag == 1) {
                return 1;
            }
            neighborsVisited++; // Increment visited neighbors count
        }
        currentNode = currentNode->next;
    }

    path.pop_back();
    return 0;
}

int rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n;
    std::vector<int> visited(N, 0); // Initialize with 0 to represent unvisited

    int result = DFS(start, G, path, visited, destination, numberOfBuilding);

    if (path.size() > numberOfBuilding) {
        return 0; // Limit path size to numberOfBuilding
    }

    return 0; // rdfs returns 0
}
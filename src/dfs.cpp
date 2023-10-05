#include "stack.hpp"
#include "graph.hpp"

int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n;
    bool visited[N] = {false};
    int trace[N] = {-1};
    
    Stack<int> stack;
    stack.push(start);
    visited[start] = true;
    
    while (!stack.empty()) {
        int u = stack.pop();
        
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
                stack.push(v);
            }
            currentNode = currentNode->next;
        }
    }
    
    int u = destination;
    while (u != -1) {
        path.insert(path.begin(), u);
        u = trace[u];
    }
    
    return 0; // DFS does not compute the number of shortest paths
}
#include <search.hpp>
#include <queue>
#include <iostream>


template <class T>
class LinkedListWrapper {
public:
    LinkedListWrapper(LinkedList<T>& list) : list(list) {}

    typename LinkedList<T>::iterator begin() {
        return list.begin();
    }

    typename LinkedList<T>::iterator end() {
        return list.end();
    }

private:
    LinkedList<T>& list;
};

template <class T>
LinkedListWrapper<T> makeWrapper(LinkedList<T>& list) {
    return LinkedListWrapper<T>(list);
}

int bfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    // Please ignore the parameter of numberOfBuilding, this parameter is only used in DFS and Recursive DFS
    // Return the number of shortest path

    int N = G.n; // Number of nodes in the graph
    std::vector<int> distance(N, -1);
    std::vector<int> parent(N, -1);
    std::queue<int> queue1;

    distance[start] = 0;
    queue1.push(start);

    while(!queue1.empty()){
        int current = queue1.front();
        queue1.pop();

    if(current == destination){
        break;
    }
    
    LinkedListWrapper<int> adjacencyNodes(G.e[current]);
    for (int neighborNode : adjacencyNodes){
        if((distance[neighborNode]) == -1){
            distance[neighborNode] == distance[current]+ 1;  
            parent[neighborNode] == current;
            queue1.push(neighborNode);
        }
    }
}

    int current = destination;
        while (current != -1){
        path.push_back(current);
        current = parent[current];
    }

    std::reverse(path.begin(), path.end());

    
    // Finally return the number of shorest paths
    int shortestPathCount = 0;
    LinkedListWrapper<int> adjacencyNodes(G.e[destination]);
        for (int neighbor : adjacencyNodes) {
            if (distance[neighbor] == distance[destination] - 1) {
                shortestPathCount++;
            }
        }
    

    return shortestPathCount; 
}

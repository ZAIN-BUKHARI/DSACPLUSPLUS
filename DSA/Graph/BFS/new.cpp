#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    // Breadth-First Search traversal
    void bfs(int startVertex) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    queue.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    // Example usage of the BFS function
    Graph graph(7);

    // Adding edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    // Perform BFS traversal starting from vertex 0
    std::cout << "BFS traversal starting from vertex 0: ";
    graph.bfs(0);
    std::cout << std::endl;

    return 0;
}

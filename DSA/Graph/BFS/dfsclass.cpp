#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    // Depth-First Search traversal
    void dfs(int startVertex) {
        std::vector<bool> visited(vertices, false); // Mark all vertices as not visited
        std::stack<int> stack;

        // Start DFS from the given vertex
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            // Process the current vertex if it has not been visited yet
            if (!visited[currentVertex]) {
                std::cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            // Push adjacent vertices onto the stack
            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    stack.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    // Example usage of the DFS function
    Graph graph(7);

    // Adding edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    // Perform DFS traversal starting from vertex 0
    std::cout << "DFS traversal starting from vertex 0: ";
    graph.dfs(0);
    std::cout << std::endl;

    return 0;
}

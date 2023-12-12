#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList; // Adjacency list to store edges and weights

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].push_back(std::make_pair(dest, weight));
        adjacencyList[dest].push_back(std::make_pair(src, weight)); // Assuming an undirected graph
    }

    // Prim's algorithm to find the Minimum Spanning Tree (MST)
    void primMST() {
        std::vector<bool> inMST(vertices, false); // To track whether a vertex is already in the MST
        std::vector<int> key(vertices, INT_MAX);   // Key values used to pick the minimum weight edge

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        // Start with the first vertex
        int src = 0;
        pq.push(std::make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (const auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(std::make_pair(key[v], v));
                }
            }
        }

        // Display the result
        std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
        for (int i = 1; i < vertices; ++i) {
            std::cout << i << " -- " << key[i] << " --> " << i << std::endl;
        }
    }
};

int main() {
    Graph graph(5);

    // Adding edges to the graph
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Applying Prim's algorithm
    graph.primMST();

    return 0;
}

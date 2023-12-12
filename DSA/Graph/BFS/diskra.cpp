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

    // Dijkstra's algorithm to find the shortest path
    void dijkstra(int src) {
        std::vector<int> dist(vertices, INT_MAX); // Distance vector to store the shortest distance from the source
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        pq.push(std::make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }

        // Display the result
        std::cout << "Shortest distances from the source " << src << " to each vertex:" << std::endl;
        for (int i = 0; i < vertices; ++i) {
            std::cout << "To " << i << ": " << dist[i] << std::endl;
        }
    }
};

int main() {
    Graph graph(6);

    // Adding edges to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 10);
    graph.addEdge(2, 3, 3);
    graph.addEdge(3, 4, 4);
    graph.addEdge(4, 5, 6);

    // Applying Dijkstra's algorithm from source vertex 0
    graph.dijkstra(0);

    return 0;
}

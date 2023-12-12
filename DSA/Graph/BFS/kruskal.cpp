#include <iostream>
#include <vector>
#include <algorithm>

class Edge {
public:
    int src, dest, weight;

    Edge(int source, int destination, int w) : src(source), dest(destination), weight(w) {}
};

class Graph {
private:
    int vertices;
    std::vector<Edge> edges;

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    // Find operation for Union-Find
    int find(std::vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Union operation for Union-Find
    void unionSets(std::vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        parent[rootX] = rootY;
    }

    // Kruskal's algorithm
    void kruskalMST() {
        // Sort edges in non-decreasing order by weight
        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        std::vector<int> parent(vertices, -1);
        std::vector<Edge> result;

        for (const Edge& edge : edges) {
            int rootSrc = find(parent, edge.src);
            int rootDest = find(parent, edge.dest);

            // If including this edge does not create a cycle, include it in the result and update Union-Find sets
            if (rootSrc != rootDest) {
                result.push_back(edge);
                unionSets(parent, rootSrc, rootDest);
            }
        }

        // Display the result
        std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
        for (const Edge& edge : result) {
            std::cout << edge.src << " -- " << edge.dest << " : " << edge.weight << std::endl;
        }
    }
};

int main() {
    Graph graph(4);

    // Adding edges to the graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Applying Kruskal's algorithm
    graph.kruskalMST();

    return 0;
}

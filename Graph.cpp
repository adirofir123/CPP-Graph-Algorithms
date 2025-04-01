//adirofir123@gmail.com
#include "Graph.hpp"

namespace graph {

    Graph::Graph(int vertices) : numVertices(vertices) {
        // Allocate adjacency matrix
        adjacencyMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    Graph::Graph(const Graph& other) : numVertices(other.numVertices) {
        adjacencyMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] = other.adjacencyMatrix[i][j];
            }
        }
    }
    

    Graph::~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight; // Undirected graph
    }

    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex index.");
        }
        if (adjacencyMatrix[src][dest] == 0) {
            throw std::invalid_argument("Edge does not exist.");
        }
        adjacencyMatrix[src][dest] = 0;
        adjacencyMatrix[dest][src] = 0;
    }

    void Graph::print_graph() const {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    std::cout << j << "(" << adjacencyMatrix[i][j] << ") ";
                }
            }
            std::cout << std::endl;
        }
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }
    
    bool Graph::hasEdge(int src, int dest) const {
        return adjacencyMatrix[src][dest] != 0;
    }
    
    int Graph::getEdgeWeight(int src, int dest) const {
        return adjacencyMatrix[src][dest];
    }
    

}

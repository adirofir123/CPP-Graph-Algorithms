#pragma once
#include <iostream>
#include <stdexcept>

namespace graph {

    class Graph {
    private:
        int numVertices;
        int** adjacencyMatrix;

    public:
        Graph(int vertices);                  // Constructor
        Graph(const Graph& other);            // Copy constructor
        ~Graph();                             // Destructor

        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph() const;
    
    
        // Helpers for Algorithms
        int getNumVertices() const;
        bool hasEdge(int src, int dest) const;
        int getEdgeWeight(int src, int dest) const;    
    };
}

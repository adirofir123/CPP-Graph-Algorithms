//adirofir123@gmail.com
#pragma once

namespace graph {

    struct PQEntry {
        int vertex;
        int distance;
        bool visited;
    };

    class PriorityQueue {
    private:
        PQEntry* data;
        int size;

    public:
        PriorityQueue(int numVertices);
        ~PriorityQueue();

        void setDistance(int vertex, int dist);
        int extractMin();
        bool isEmpty() const;
        bool isVisited(int vertex) const;
        void markVisited(int vertex);
        int getDistance(int vertex) const;
    };

}

//adirofir123@gmail.com
#include "PriorityQueue.hpp"
#include <limits>

namespace graph {

    PriorityQueue::PriorityQueue(int numVertices) : size(numVertices) {
        data = new PQEntry[size];
        for (int i = 0; i < size; ++i) {
            data[i].vertex = i;
            data[i].distance = std::numeric_limits<int>::max();
            data[i].visited = false;
        }
    }

    PriorityQueue::~PriorityQueue() {
        delete[] data;
    }

    void PriorityQueue::setDistance(int vertex, int dist) {
        data[vertex].distance = dist;
    }

    int PriorityQueue::extractMin() {
        int minDist = std::numeric_limits<int>::max();
        int minIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (!data[i].visited && data[i].distance < minDist) {
                minDist = data[i].distance;
                minIndex = i;
            }
        }
        return minIndex;
    }

    bool PriorityQueue::isEmpty() const {
        for (int i = 0; i < size; ++i) {
            if (!data[i].visited)
                return false;
        }
        return true;
    }

    bool PriorityQueue::isVisited(int vertex) const {
        return data[vertex].visited;
    }

    void PriorityQueue::markVisited(int vertex) {
        data[vertex].visited = true;
    }

    int PriorityQueue::getDistance(int vertex) const {
        return data[vertex].distance;
    }

}

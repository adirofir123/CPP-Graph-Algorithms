//adirofir123@gmail.com
#include "Queue.hpp"
#include <stdexcept>

namespace graph {

    Queue::Queue(int size) : front(0), rear(0), capacity(size) {
        data = new int[capacity];
    }

    Queue::~Queue() {
        delete[] data;
    }

    void Queue::enqueue(int value) {
        if (rear >= capacity)
            throw std::overflow_error("Queue overflow");
        data[rear++] = value;
    }

    int Queue::dequeue() {
        if (isEmpty())
            throw std::underflow_error("Queue underflow");
        return data[front++];
    }

    bool Queue::isEmpty() const {
        return front == rear;
    }

}

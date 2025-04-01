#pragma once

namespace graph {

    class Queue {
    private:
        int* data;
        int front;
        int rear;
        int capacity;

    public:
        Queue(int size);
        ~Queue();

        void enqueue(int value);
        int dequeue();
        bool isEmpty() const;
    };

}

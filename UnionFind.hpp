//adirofir123@gmail.com
#pragma once

namespace graph {

    class UnionFind {
    private:
        int* parent;
        int* rank;
        int size;

    public:
        UnionFind(int n);
        ~UnionFind();

        int find(int x);
        void unionSets(int x, int y);
    };

}

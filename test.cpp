//adirofir123@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

void test_basic_graph() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.removeEdge(2, 3);

    try {
        g.removeEdge(2, 3); // Should throw
        std::cout << "Failed: removeEdge did not throw on missing edge\n";
    } catch (...) {
        std::cout << "Passed: removeEdge throws on missing edge\n";
    }
}

void test_bfs() {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    Graph bfsTree = Algorithms::bfs(g, 0);
    if (bfsTree.hasEdge(0, 1) && bfsTree.hasEdge(1, 2)) {
        std::cout << "Passed: BFS tree includes expected edges\n";
    } else {
        std::cout << "Failed: BFS tree missing expected edges\n";
    }
}

int main() {
    std::cout << "[Running Tests]\n";
    test_basic_graph();
    test_bfs();
    std::cout << "[Done]\n";
    return 0;
}

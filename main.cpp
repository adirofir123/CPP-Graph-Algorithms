//adirofir123@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    std::cout << "Original graph:\n";
    g.print_graph();

    Graph bfsTree = Algorithms::bfs(g, 0);
    std::cout << "\nBFS tree from node 0:\n";
    bfsTree.print_graph();

    Graph dfsTree = Algorithms::dfs(g, 0);
    std::cout << "\nDFS tree from node 0:\n";
    dfsTree.print_graph();

    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    std::cout << "\nDijkstra shortest-path tree from node 0:\n";
    dijkstraTree.print_graph();

    Graph primTree = Algorithms::prim(g);
    std::cout << "\nPrim MST:\n";
    primTree.print_graph();

    Graph kruskalTree = Algorithms::kruskal(g);
    std::cout << "\nKruskal MST:\n";
    kruskalTree.print_graph();

    return 0;
}

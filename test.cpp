//adirofir123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

TEST_CASE("Graph basic edge operations") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    CHECK(g.hasEdge(0, 1));
    CHECK(g.hasEdge(1, 2));
    CHECK(!g.hasEdge(0, 2));

    g.removeEdge(1, 2);
    CHECK(!g.hasEdge(1, 2));
}

TEST_CASE("removeEdge throws when edge does not exist") {
    Graph g(3);
    CHECK_THROWS_AS(g.removeEdge(0, 1), std::invalid_argument);
}

TEST_CASE("Edge weight is returned correctly") {
    Graph g(3);
    g.addEdge(0, 1, 7);
    CHECK(g.getEdgeWeight(0, 1) == 7);
    CHECK(g.getEdgeWeight(1, 0) == 7); // undirected
}

TEST_CASE("hasEdge reflects correct state") {
    Graph g(3);
    CHECK(!g.hasEdge(0, 2));
    g.addEdge(0, 2);
    CHECK(g.hasEdge(0, 2));
    g.removeEdge(0, 2);
    CHECK(!g.hasEdge(0, 2));
}

TEST_CASE("Copy constructor creates independent copy") {
    Graph g1(3);
    g1.addEdge(0, 1, 9);

    Graph g2 = g1; // deep copy
    CHECK(g2.hasEdge(0, 1));
    g2.removeEdge(0, 1);
    CHECK(g1.hasEdge(0, 1)); // g1 should NOT be affected
}

TEST_CASE("Graph BFS") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    Graph bfsTree = Algorithms::bfs(g, 0);

    CHECK(bfsTree.hasEdge(0, 1));
    CHECK(bfsTree.hasEdge(1, 2));
    CHECK(!bfsTree.hasEdge(0, 2));
}

TEST_CASE("Graph DFS") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);

    CHECK(dfsTree.hasEdge(0, 1));
    CHECK(dfsTree.hasEdge(1, 3));
    CHECK(dfsTree.hasEdge(0, 2)); // DFS may reach 2 early or later
}

TEST_CASE("Dijkstra returns correct shortest paths") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 3, 1);

    Graph tree = Algorithms::dijkstra(g, 0);
    CHECK(tree.hasEdge(0, 1));
    CHECK(tree.hasEdge(1, 2)); // 0→1→2 is shorter than 0→2
    CHECK(tree.hasEdge(2, 3));
}

TEST_CASE("Dijkstra throws on negative edge weight") {
    Graph g(3);
    g.addEdge(0, 1, -4);  // illegal for Dijkstra
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Prim returns minimum spanning tree") {
    Graph g(4);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.hasEdge(0, 2)); // weight 1
    CHECK(mst.hasEdge(1, 2)); // weight 2
    CHECK(mst.hasEdge(2, 3)); // weight 3
}

TEST_CASE("Kruskal returns minimum spanning tree") {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.hasEdge(2, 3)); // weight 4
    CHECK(mst.hasEdge(0, 3)); // weight 5
    CHECK(mst.hasEdge(0, 1)); // weight 10 (next lowest that doesn't form a cycle)
}

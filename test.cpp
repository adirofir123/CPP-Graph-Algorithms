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

TEST_CASE("Graph BFS") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    Graph bfsTree = Algorithms::bfs(g, 0);

    CHECK(bfsTree.hasEdge(0, 1));
    CHECK(bfsTree.hasEdge(1, 2));
    CHECK(!bfsTree.hasEdge(0, 2));
}

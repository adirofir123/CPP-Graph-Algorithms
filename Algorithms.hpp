//adirofir123@gmail.com
#pragma once
#include "Graph.hpp"

namespace graph {

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int start);
        static Graph dfs(const Graph& g, int start);
        static Graph dijkstra(const Graph& g, int start);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);
    };

}

// adirofir123@gmail.com
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include <stdexcept>
#include <limits>

namespace graph
{

    Graph Algorithms::bfs(const Graph &g, int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
            throw std::out_of_range("Invalid start vertex");

        Graph bfsTree(n); // Tree to return

        bool *visited = new bool[n];
        for (int i = 0; i < n; ++i)
            visited[i] = false;

        Queue q(n);
        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty())
        {
            int u = q.dequeue();

            for (int v = 0; v < n; ++v)
            {
                if (g.hasEdge(u, v) && !visited[v])
                {
                    visited[v] = true;
                    bfsTree.addEdge(u, v, g.getEdgeWeight(u, v));
                    q.enqueue(v);
                }
            }
        }

        delete[] visited;
        return bfsTree;
    }

    static void dfsRecursive(const Graph &g, Graph &tree, bool *visited, int u)
    {
        visited[u] = true;

        for (int v = 0; v < g.getNumVertices(); ++v)
        {
            if (g.hasEdge(u, v) && !visited[v])
            {
                tree.addEdge(u, v, g.getEdgeWeight(u, v));
                dfsRecursive(g, tree, visited, v);
            }
        }
    }

    Graph Algorithms::dfs(const Graph &g, int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
            throw std::out_of_range("Invalid start vertex");

        Graph tree(n);
        bool *visited = new bool[n];
        for (int i = 0; i < n; ++i)
            visited[i] = false;

        dfsRecursive(g, tree, visited, start);

        delete[] visited;
        return tree;
    }

    Graph Algorithms::dijkstra(const Graph &g, int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
            throw std::out_of_range("Invalid start vertex");

        //  Check for negative edge weights
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g.hasEdge(i, j) && g.getEdgeWeight(i, j) < 0)
                {
                    throw std::invalid_argument("Dijkstra does not support negative edge weights.");
                }
            }
        }
        Graph tree(n); // Will store the shortest path tree
        PriorityQueue pq(n);
        int *parent = new int[n];

        for (int i = 0; i < n; ++i)
        {
            parent[i] = -1;
        }

        pq.setDistance(start, 0);

        while (!pq.isEmpty())
        {
            int u = pq.extractMin();
            if (u == -1)
                break;

            pq.markVisited(u);

            for (int v = 0; v < n; ++v)
            {
                if (g.hasEdge(u, v) && !pq.isVisited(v))
                {
                    int alt = pq.getDistance(u) + g.getEdgeWeight(u, v);
                    if (alt < pq.getDistance(v))
                    {
                        pq.setDistance(v, alt);
                        parent[v] = u;
                    }
                }
            }
        }

        // Reconstruct the shortest path tree using parent[]
        for (int v = 0; v < n; ++v)
        {
            if (parent[v] != -1)
            {
                int u = parent[v];
                tree.addEdge(u, v, g.getEdgeWeight(u, v));
            }
        }

        delete[] parent;
        return tree;
    }

    Graph Algorithms::prim(const Graph &g)
    {
        int n = g.getNumVertices();
        if (n == 0)
            return Graph(0);

        Graph mst(n);
        PriorityQueue pq(n);
        int *parent = new int[n];

        for (int i = 0; i < n; ++i)
        {
            pq.setDistance(i, std::numeric_limits<int>::max());
            parent[i] = -1;
        }

        pq.setDistance(0, 0); // Start from vertex 0

        while (!pq.isEmpty())
        {
            int u = pq.extractMin();
            if (u == -1)
                break;

            pq.markVisited(u);

            for (int v = 0; v < n; ++v)
            {
                int weight = g.getEdgeWeight(u, v);
                if (g.hasEdge(u, v) && !pq.isVisited(v) && weight < pq.getDistance(v))
                {
                    pq.setDistance(v, weight);
                    parent[v] = u;
                }
            }
        }

        for (int v = 0; v < n; ++v)
        {
            if (parent[v] != -1)
            {
                mst.addEdge(v, parent[v], g.getEdgeWeight(v, parent[v]));
            }
        }

        delete[] parent;
        return mst;
    }

    struct Edge
    {
        int u, v, weight;
    };

    // Simple bubble sort for small edge list
    void sortEdges(Edge *edges, int count)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = 0; j < count - i - 1; ++j)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    Graph Algorithms::kruskal(const Graph &g)
    {
        int n = g.getNumVertices();
        Graph mst(n);
        UnionFind uf(n);

        // Collect all edges
        int edgeCapacity = n * (n - 1) / 2;
        Edge *edges = new Edge[edgeCapacity];
        int edgeCount = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (g.hasEdge(i, j))
                {
                    edges[edgeCount++] = {i, j, g.getEdgeWeight(i, j)};
                }
            }
        }

        // Sort edges by weight
        sortEdges(edges, edgeCount);

        // Add safe edges
        for (int i = 0; i < edgeCount; ++i)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            if (uf.find(u) != uf.find(v))
            {
                uf.unionSets(u, v);
                mst.addEdge(u, v, edges[i].weight);
            }
        }

        delete[] edges;
        return mst;
    }

}

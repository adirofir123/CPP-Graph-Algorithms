# Graph Algorithms Project – C++

This project implements core graph algorithms in C++ without using the STL. It is part of an academic assignment focused on understanding memory management, class design, and data structures.

## Features

- Namespace: `graph`
- Class: `Graph` – Undirected weighted graph using an adjacency matrix
- Class: `Algorithms` – Graph algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Dijkstra’s Algorithm
  - Prim’s Minimum Spanning Tree
  - Kruskal’s Minimum Spanning Tree

## Custom Data Structures (No STL)

- `Queue` – Used in BFS
- `PriorityQueue` – Used in Dijkstra and Prim
- `UnionFind` – Used in Kruskal

## File Structure

- `main.cpp` – Demonstrates usage of all graph algorithms
- `Graph.hpp / Graph.cpp` – Graph implementation
- `Algorithms.hpp / Algorithms.cpp` – Graph algorithms
- `Queue.hpp / Queue.cpp` – Basic queue
- `PriorityQueue.hpp / PriorityQueue.cpp` – Min-priority queue
- `UnionFind.hpp / UnionFind.cpp` – Disjoint-set structure
- `README.md` – This file
- `Makefile` – Build commands

## How to Compile and Run

```bash
make Main    # Build main program
./Main       # Run main demo

```

## How to run Tests

This project uses [doctest](https://github.com/doctest/doctest) for unit testing.

To run the tests:

```bash
make test    # Run unit tests (see test.cpp)
```

## Memory Leak Check

```bash
make valgrind
```

## Clean Build Files

```bash
make clean
```




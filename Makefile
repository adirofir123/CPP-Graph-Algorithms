#adirofir123@gmail.com
# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRC = main.cpp Graph.cpp Algorithms.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
TARGET = Main

# Build the program
Main: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) 
	./Main

# Build and run unit tests
test: test.cpp Graph.cpp Algorithms.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp Graph.cpp Algorithms.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
	./test
	
# Run valgrind to check memory leaks
valgrind: Main
	valgrind --leak-check=full ./Main

# Clean up compiled files
clean:
	rm -f $(TARGET) *.o

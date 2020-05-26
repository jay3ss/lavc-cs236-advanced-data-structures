/** @file: Graph.cpp
The depth-first search (DFS) is similar to the preorder traversal of a binary
tree. In the case of a tree, the search starts from the root. In a graph, the
search can start from any vertex in the graph and visits all vertices in the
graph as far as possible before backtracking.

The breadth-first search (BFS) also starts at the root of the tree, but unlike
DFS it explores the neighbor nodes first, before moving to the next level
neighbors.  In other words, BFS explores vertices in the order of their
distance from the source vertex, where distance is the minimum length of a
path from source vertex to the node.

You are given the map of 12 cities. The cities can be represented as a string of
vertices:

string vertices[] = {
    "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas", "Chicago",
    "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"
}; */

#include "Graph.h"

// Constructor
template <class T>
Graph<T>::Graph() {}

// Constructor
template <class T>
Graph<T>::Graph(const int numVertices)
    : numberOfVertices(numVertices)
{
    init(numVertices);
}

// Destructor
template <class T>
Graph<T>::~Graph() {}

// Adds an edge between to vertices to the graph and if either of the vertices
// don't exist, it creates them and adds them to the graph
template <class T>
bool Graph<T>::add(const T& start, const T& end, const int edgeWeight)
{
    return false;
}

// Performs a breadth-first search of this graph beginning at the given vertex
// and calls a given function once for each vertex visited
template <class T>
void Graph<T>::breadthFirstTraversal(const T &start, void callback(T &))
{

}

// Performs a depth-first search of this graph beginning at the given vertex
// and calls a given function once for each vertex visited
template <class T>
void Graph<T>::depthFirstTraversal(const T &start, void callback(T &))
{

}

// Gets the weight of an edge in the graph
template <class T>
int Graph<T>::edgeWeight(const T& start, const T& end)
{
    return -1;
}

// Initializes the graph
template <class T>
void Graph<T>::init(const int numVertices)
{
    numberOfVertices = numVertices;
    vertexValues.reserve(numVertices);
    initAdjMatrix();
}

// Gets the number of edges in the graph
template <class T>
int Graph<T>::numEdges() const
{
    return -1;
}

// Gets the number of vertices in the graph
template <class T>
int Graph<T>::numVertices() const
{
    return -1;
}

// Removes an edge from this graph
template <class T>
bool Graph<T>::remove(const T& start, const T& end)
{
    return false;
}

// Private methods
// Initiates the adjacency matrix with all 0s
template <class T>
void Graph<T>::initAdjMatrix()
{
    // reserve the correct number of rows, then iteratively reserve the correct
    // number of columns
    adjMatrix.reserve(numberOfVertices);
    for (int row = 0; row < numberOfVertices; row++)
    {
        adjMatrix[row] = std::vector<int>(numberOfVertices, 0);
    }
}

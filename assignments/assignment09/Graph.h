/** @file: Graph.h
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
};

Write a C++ program to display the Depth-First Search and Breadth-First Search
starting at any vertex (index) inputting from the user.

Sample output:

Graph Traversals
Enter starting city using number from 0 - 11: 2
You entered city name: Los Angeles

Starting at Los Angeles, 12 cities are searched in this Depth-First Search
order:
Los Angeles, San Francisco, Seattle, Denver, Kansas, Chicago, Boston, New York,
Atlanta, Miami, Houston, Dallas,
Starting at Los Angeles, 12 cities are searched in this Breadth-First Search
order:
Los Angeles, San Francisco, Denver, Kansas, Dallas, Seattle, Chicago, New York,
Atlanta, Houston, Boston, Miami,

Try another city (Y/N) Y

Enter starting city using number from 0 - 11: 5
You entered city name: Chicago

Starting at Chicago, 12 cities are searched in this Depth-First Search order:
Chicago, Seattle, San Francisco, Los Angeles, Denver, Kansas, New York, Boston,
Atlanta, Miami, Houston, Dallas,

Starting at Chicago, 12 cities are searched in this Breadth-First Search order:
Chicago, Seattle, Denver, Kansas, Boston, New York, San Francisco, Los Angeles,
Atlanta, Dallas, Miami, Houston,
Try another city (Y/N) N */
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template <class T>
class Graph
{
public:
    /** Constructor */
    Graph();

    /** Constructor
    @param numVertices The number of vertices in the graph */
    Graph(const int numVertices);

    /** Destructor */
    ~Graph();

    /** Adds an edge between to vertices to the graph and if either of the
        vertices don't exist, it creates them and adds them to the graph
    @pre: 0 <= start < numVertices and  0 <= end < numVertices
        0 < edgeWeight
    @param start The starting vertex
    @param end The ending vertex
    @param edgeWeight The integer weight of the edge
    @return True if the edge was added */
    bool add(const int start, const int end, const int edgeWeight);

    /** Performs a breadth-first search of this graph beginning at the given
        vertex and calls a given function once for each vertex visited
    @param start The starting vertex
    @param callback The client-provided callback function to process the
        vertices */
    void breadthFirstTraversal(const int start, void callback(T&));

    /** Performs a depth-first search of this graph beginning at the given
        vertex and calls a given function once for each vertex visited
    @param start The starting vertex
    @param callback The client-provided callback function to process the
        vertices */
    void depthFirstTraversal(const int start, void callback(T &));

    /** Gets the weight of an edge in the graph
    @param pre The edge must exist and 0 <= start <= numVertices - 1 and
        0 <= end <= numVertices - 1
    @param start The starting vertex
    @param end The ending vertex
    @return The weight of the edge */
    int edgeWeight(const int start, const int end);

    /** Initializes the graph
    @param numVertices The number of vertices in the graph
    @post The graph will be initiated including the adjacency matrix will be
        of the size numVertices x numVertices and will have every entry be 0 */
    void init(const int numVertices);

    /** Gets the number of edges in the graph
    @return The number of edges in the graph */
    int numEdges() const;

    /** Gets the number of vertices in the graph
    @return The number of vertices in the graph */
    int numVertices() const;

    /** Removes an edge from this graph
    @param start The starting vertext
    @param end The ending vertext
    @return True if the edge was removed, false otherwise */
    bool remove(const int start, const int end);

    /** Returns the weight value for an edge
    @pre 0 <= start < numVertices and  0 <= end < numVertices
    @param start The starting vertext
    @param end The ending vertext
    @return The integer value of the edge */
    int weight(const int start, const int end);

    class OutOfRange
    {
    private:
        int vertNumber;
    public:
        OutOfRange(const int n)
            { vertNumber = n; }
        int getValue() const
            { return vertNumber; }
    };

    class InvalidWeight
    {
    private:
        int weight;
    public:
        InvalidWeight(const int w)
            { weight = w; }
        int getValue() const
            { return weight; }
    };
private:
    int numberOfVertices;   // The number of vertices in the graph
    int numberOfEdges;      // The number of edges in the graph

    std::vector<std::vector<int>> adjMatrix;  // The adjacency matrix
    std::vector<T> vertexValues;              // Hold the values of the graph vertices

    /** Initiates the adjacency matrix with all 0s
    @post The adjacency matrix (adjMatrix) will be all 0s. Any values currently
        in it will be overwritten */
    void initAdjMatrix();
};

#include "Graph.cpp"

#endif // GRAPH_H

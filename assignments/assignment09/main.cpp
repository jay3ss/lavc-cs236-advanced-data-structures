/** @file: main.cpp
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
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Graph.h"

using namespace std;

typedef pair<string, vector<string>> cities;

int positionOf(vector<string> vect, string city);
void print(const string& value);

int main()
{

    vector<string> vertices = {
        "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas", "Chicago",
        "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"
    };
    map<string, vector<string>> edges;

    // Create the connections between cities
    // Seattle: SF, Denver, Chicago
    edges.insert(cities(vertices[0], {vertices[1], vertices[3], vertices[5]}));

    // San Francisco: Seattle, LA, Denver
    edges.insert(cities(vertices[1], {vertices[0], vertices[2], vertices[3]}));

    // LA: SF, Denver, KC, Dallas
    edges.insert(cities(vertices[2], {vertices[1], vertices[3], vertices[4], vertices[10]}));

    // Denver: Seattle, SF, LA, KC, Chicago
    edges.insert(cities(vertices[3], {vertices[0], vertices[1], vertices[2], vertices[4], vertices[5]}));

    // KC: LA, Denver, Chicago, NYC, Atlanta, Dallas
    edges.insert(cities(vertices[4], {vertices[2], vertices[3], vertices[5], vertices[7], vertices[8], vertices[10]}));

    // Chicago: Seattle, Denver, KC, Boston, NYC
    edges.insert(cities(vertices[5], {vertices[0], vertices[3], vertices[4], vertices[6], vertices[7]}));

    // Boston: Chicago, NYC
    edges.insert(cities(vertices[6], {vertices[5], vertices[7]}));

    // NYC: KC, Chicago, Boston, Atlanta
    edges.insert(cities(vertices[7], {vertices[4], vertices[5], vertices[6], vertices[8]}));

    // Atlanta: KC, NYC, Miami, Dallas, Houston
    edges.insert(cities(vertices[8], {vertices[4], vertices[7], vertices[9], vertices[10], vertices[11]}));

    // Miami: Atlanta, Houston
    edges.insert(cities(vertices[9], {vertices[8], vertices[11]}));

    // Dallas: LA, KC, Atlanta, Houston
    edges.insert(cities(vertices[10], {vertices[2], vertices[4], vertices[8], vertices[11]}));

    // Houston: Atlanta, Miami, Houston
    edges.insert(cities(vertices[11], {vertices[8], vertices[9], vertices[10]}));

    const int NUM_VERTICES = 12;

    Graph<string> graph(NUM_VERTICES);

    // Go through each vertex
    for (int vertNum = 0; vertNum < NUM_VERTICES; vertNum++)
    {
        string vertex = vertices[vertNum];
        auto connections = edges[vertex];
        cout << vertex << ": ";

        // Go through each edge for the vertex
        for (auto& connection : connections)
        {
            int connectionNum = positionOf(vertices, connection);

            if (connectionNum >= 0)
            {
                cout << connection << " ";
                graph.add(vertNum, connectionNum, 1);
            }
        }
        cout << endl;
    }

    return 0;
}

int positionOf(vector<string> vect, string city)
{
    int position = -1;
    int idx = 0;
    bool found = false;

    while (idx < vect.size() && !found)
    {
        if (vect[idx] == city)
        {
            position = idx;
            found = true;
        }
        idx++;
    }

    return position;
}

void print(const string& value)
{
    cout << value << ", ";
}

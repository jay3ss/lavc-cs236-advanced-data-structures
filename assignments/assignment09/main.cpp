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
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Graph.h"

using namespace std;

typedef pair<string, vector<string>> cities;

// Adds edges to the graph
void addEdges(Graph<string>& graph, vector<string>& cities);

// Creates the graph of the cities
Graph<string> createCityGraph(vector<string>& cityNames);

// Creates a map of cities (vertex) and their neighbors (edges)
void createEdges(map<string, vector<string>>& edges, vector<string>& cities);

// Gets, validates, and returns the city choice of the user
int getCityChoice(const int size);

// Gets, validates, and returns the choice of whether or not to continue from the user
int getContinueChoice();

// Displays a menu to the user and interacts with the user
void menu(Graph<string>& graph);

// Finds and returns the position of a string within an vector<string>
int positionOf(vector<string>& vect, string city);

// Callback function that prints the values in the graph
void print(const string& value);

// Sets the names of the cities in the graph
void setCityNames(Graph<string>& graph, vector<string>& cityNames);

int main()
{
    vector<string> vertices = {
        "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas", "Chicago",
        "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"
    };

    Graph<string> graph = createCityGraph(vertices);
    menu(graph);

    return 0;
}

/** Adds edges to the graph
@param: graph The graph to add edges to
@param: cityNames The vector holding the names of the cities
@post: The graph will have its vertices associated with the names of the
    cities */
void addEdges(Graph<string>& graph, vector<string>& cityNames)
{
    map<string, vector<string>> edges;
    createEdges(edges, cityNames);

    for (int vertNum = 0; vertNum < cityNames.size(); vertNum++)
    {
        string cityName = cityNames[vertNum];
        auto connections = edges[cityName];

        // Go through each edge for the vertex
        for (auto &connection : connections)
        {
            int connectionNum = positionOf(cityNames, connection);

            if (connectionNum >= 0)
                graph.add(vertNum, connectionNum, 1);
        }
    }
}

/** Creates the graph of the cities
@param: cityNames The vector containing the names of the cities
@return: A Graph object with the cities as vertices and vertex values and
    neighboring cities as edges */
Graph<string> createCityGraph(vector<string>& cityNames)
{
    const int NUM_VERTICES = 12;
    Graph<string> graph(NUM_VERTICES);
    addEdges(graph, cityNames);
    setCityNames(graph, cityNames);

    return graph;
}

/** Creates a map of cities (vertex) and their neighbors (edges)
@param: edges A map
@param: cityNames A vector containing the names of cities
@post: The map object (edges) will have city names as the keys and the neighboring
    cities as the values */
void createEdges(map<string, vector<string>>& edges, vector<string>& cityNames)
{
    // Create the connections between cities
    // Seattle: SF, Denver, Chicago
    edges.insert(cities(cityNames[0], {cityNames[1], cityNames[3], cityNames[5]}));

    // San Francisco: Seattle, LA, Denver
    edges.insert(cities(cityNames[1], {cityNames[0], cityNames[2], cityNames[3]}));

    // LA: SF, Denver, KC, Dallas
    edges.insert(cities(cityNames[2], {cityNames[1], cityNames[3], cityNames[4], cityNames[10]}));

    // Denver: Seattle, SF, LA, KC, Chicago
    edges.insert(cities(cityNames[3], {cityNames[0], cityNames[1], cityNames[2], cityNames[4], cityNames[5]}));

    // KC: LA, Denver, Chicago, NYC, Atlanta, Dallas
    edges.insert(cities(cityNames[4], {cityNames[2], cityNames[3], cityNames[5], cityNames[7], cityNames[8], cityNames[10]}));

    // Chicago: Seattle, Denver, KC, Boston, NYC
    edges.insert(cities(cityNames[5], {cityNames[0], cityNames[3], cityNames[4], cityNames[6], cityNames[7]}));

    // Boston: Chicago, NYC
    edges.insert(cities(cityNames[6], {cityNames[5], cityNames[7]}));

    // NYC: KC, Chicago, Boston, Atlanta
    edges.insert(cities(cityNames[7], {cityNames[4], cityNames[5], cityNames[6], cityNames[8]}));

    // Atlanta: KC, NYC, Miami, Dallas, Houston
    edges.insert(cities(cityNames[8], {cityNames[4], cityNames[7], cityNames[9], cityNames[10], cityNames[11]}));

    // Miami: Atlanta, Houston
    edges.insert(cities(cityNames[9], {cityNames[8], cityNames[11]}));

    // Dallas: LA, KC, Atlanta, Houston
    edges.insert(cities(cityNames[10], {cityNames[2], cityNames[4], cityNames[8], cityNames[11]}));

    // Houston: Atlanta, Miami, Houston
    edges.insert(cities(cityNames[11], {cityNames[8], cityNames[9], cityNames[10]}));
}

/** Gets, validates, and returns the city choice of the user
@param: size The integer number of cities
@return: The choice of the user 0 <= cityChoice < size */
int getCityChoice(const int size)
{
    int cityChoice;
    string cityPrompt = "Enter starting city using number from 0 - 11 : ";

    cout << cityPrompt;
    cin >> cityChoice;
    cin.ignore();

    while (0 > cityChoice || cityChoice >= size)
    {
        cerr << "The vertex " << cityChoice << " does not exist. "
             << "Please try again.\n";

        cout << cityPrompt;
        cin >> cityChoice;
        cin.ignore();
    }

    return cityChoice;
}

/** Gets, validates, and returns the choice of whether or not to continue from
    the user
@return: The choice of the user: either Y/y/N/n */
int getContinueChoice()
{
    char continueChoice;
    string continuePrompt = "Try another city (Y/N) ";

    cout << continuePrompt;
    cin >> continueChoice;
    cin.ignore();

    while (tolower(continueChoice) != 'y' && tolower(continueChoice) != 'n')
    {
        cout << "Invalid choice. Please enter a 'Y/y' or 'N/n'.\n";
        cout << continuePrompt;
        cin >> continueChoice;
        cin.ignore();
    }

    return continueChoice;
}

/** Finds and returns the position of a string within an vector<string>
@param: vect The vector to search
@param: city The city to find
@return: The position of the city within the vector, if found, -1 if not found */
int positionOf(vector<string>& vect, string city)
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

/** Displays a menu to the user and interacts with the user
@param: graph The graph to traverse
@param: cityNames Vector holding the names */
void menu(Graph<string>& graph)
{
    vector<string> cityNames = graph.values();
    char continueChoice = 'y';
    int cityChoice;

    string continuePrompt = "\n\nTry another city (Y/N) ";
    string citiesMessage = ", 12 cities are searched in this Breadth-First Search order:\n";

    cout << "Graph Traversals\n";

    while (tolower(continueChoice) != 'n')
    {
        cityChoice = getCityChoice(cityNames.size());
        cout << "You entered city name: " << cityNames[cityChoice] << "\n\n";

        cout << "Starting at " << cityNames[cityChoice]
             << ", 12 cities are searched in this Depth-First Search order:\n";
        graph.depthFirstTraversal(cityChoice, print);

        cout << "\n\nStarting at " << cityNames[cityChoice]
             << ", 12 cities are searched in this Breadth-First Search order:\n";
        graph.breadthFirstTraversal(cityChoice, print);

        cout << "\n\n";

        continueChoice = getContinueChoice();
    }
}

/** Callback function that prints the values in the graph
@param: value The vertex value to be printed to the console
@post: The vertex values will be printed to the console */
void print(const string& value)
{
    cout << value << ", ";
}

/** Sets the names of the cities in the graph
@param: graph The graph to set the city names to
@param: cityName The city names that will populate the graph
@post: The graph will have the city names as the vertex values */
void setCityNames(Graph<string>& graph, vector<string>& cityNames)
{
    for (int i = 0; i < cityNames.size(); i++)
        graph.value(i, cityNames[i]);
}

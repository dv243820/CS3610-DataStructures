
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
using namespace std;
class weightedGraphType
{
public:
    void createWeightedGraph();
    // Function to create the graph and the weight matrix.
    // Postcondition: The graph using adjacency lists and
    //  its weight matrix is created
    void shortestPath(int vertex);
    // Function to determine the weight of a shortest path
    // from vertex, that is, source, to every other vertex
    // in the graph.
    // Postcondition: The weight of the shortest path from vertex
    //  to every other vertex in the graph is determined.
    void printShortestPath(int vertex);

    weightedGraphType(int size = 0);
    // Constructor
    // Postcondition: gSize = 0; maxSize = size;
    //  graph is an array of pointers to linked lists.
    //  weights is a two-dimensional array to store the weights
    //  of the edges.
    //  smallestWeight is an array to store the smallest weight
    //  from source to vertices.
    ~weightedGraphType();
    // Destructor
    // The storage occupied by the vertices and the arrays
    // weights and smallestWeight is deallocated.
protected:
    int gSize;
    string *vertices;
    double **weights;
    double *smallestWeight; // the smallest weight from source to vertices
    int *shortestPathArr;
    int *pred;
};
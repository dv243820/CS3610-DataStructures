#include "wgt.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat> //included for DBL_MAX from the notes (INFINITY)
#include <stack>  // I used a stack to output
using namespace std;

void weightedGraphType::createWeightedGraph()
{
    cin >> gSize;

    // Allocate memory for vertices and weights
    vertices = new string[gSize];
    weights = new double *[gSize];
    pred = new int[gSize];            // pred array to keep track of the predecessor of each vertex along the shortest path from the starting vertex
    shortestPathArr = new int[gSize]; // USED TO FIND PATH BETWEEN FIRST AND LAST INDEX
    for (int i = 0; i < gSize; i++)
    {
        shortestPathArr[i] = -1; // -1 means no path found
    }

    for (int i = 0; i < gSize; i++)
    {
        weights[i] = new double[gSize];
    }

    for (int j = 0; j < gSize; j++)
    {
        pred[j] = -1; // -1 means no predecessor
    }

    // Read the names of the vertices
    for (int i = 0; i < gSize; i++)
    {
        cin >> vertices[i];
    }

    for (int i = 0; i < gSize; i++)
    {
        for (int j = 0; j < gSize; j++)
        {
            cin >> weights[i][j];
            if (weights[i][j] == 0) // the input was 0, which means there isnt a path. SET TO INFINITY INSTEAD!!!!!!!!!!!!!!
            {
                weights[i][j] = DBL_MAX;
            }
        }
    }
}

// shortest path aka DIJKSTRAS ALGORITHM
void weightedGraphType::shortestPath(int vertex)
{
    // Initialize smallestWeight array with weights of edges from the starting vertex to all other vertices
    for (int j = 0; j < gSize; j++)
    {
        smallestWeight[j] = weights[vertex][j];
    }

    // Initialize weightFound array to keep track of whether the shortest path to each vertex has been found
    bool *weightFound;
    weightFound = new bool[gSize];
    for (int j = 0; j < gSize; j++)
    {
        weightFound[j] = false;
    }

    // Mark starting vertex as having been found and set its smallest weight to 0
    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    // Find the shortest path to each vertex
    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = DBL_MAX; //INFINITY FROM NOTES!!!!!!
        int v;

        // Find the vertex with the smallest weight that has not been found yet
        for (int j = 0; j < gSize; j++)
        {
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight)
                {
                    v = j;
                    minWeight = smallestWeight[v];
                }
        }

        // Mark the vertex as having been found
        weightFound[v] = true;

        // Update the smallestWeight array with the smallest weight found so far for each vertex
        for (int j = 0; j < gSize; j++)
        {
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                {
                    smallestWeight[j] = minWeight + weights[v][j];
                    pred[j] = v; // update predecessor of vertex j
                    shortestPathArr[j] = v;
                }
        }

    } // end for


} // end shortestPath

void weightedGraphType::printShortestPath(int vertex)
{

    int curr = shortestPathArr[gSize - 1];
    stack<int> pathStack; // USES A STACK
    pathStack.push(gSize - 1);
    while (curr != vertex)
    {
        pathStack.push(curr);
        curr = pred[curr];
    }
    pathStack.push(vertex);

    while (!pathStack.empty()) // UNTIL WE GET TO END OF STACK
    {
        if (pathStack.top() != -1) //IF NOT -1, ON THE PATH
        {
            cout << vertices[pathStack.top()] << " ";
        }
        pathStack.pop();
    }
    cout << smallestWeight[gSize - 1] << endl; // outputs the smallestWeight from city_1 to city_n
}

// Constructor
weightedGraphType::weightedGraphType(int size)
{
    weights = new double *[size];
    for (int i = 0; i < size; i++)
    {
        weights[i] = new double[size];
    }
    smallestWeight = new double[size];
}

// Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < gSize; i++)
    {
        delete[] weights[i];
    }
    delete[] weights;
    delete[] smallestWeight;
    delete[] shortestPathArr;
    delete[] pred;
    gSize = 0;
}
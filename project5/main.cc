/**
 *        @file: main.cc
 *      @author: Drew VanAtta
 *        @date: April 18, 2023
 *       @brief: main.cc for Dijkstra's Algorithm
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include "wgt.h"
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{
    int testcases = 0;
    cin >> testcases; // user input the amount of test cases for the graph
    weightedGraphType graph;

    for (int i = 0; i < testcases; i++)
    {
        // set up the graph with user inputs
        graph.createWeightedGraph();

        // find shortest path of first index spot
        graph.shortestPath(0);
        graph.printShortestPath(0);
    }

    return 0;
} // main
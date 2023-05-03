#pragma once
#include "CustomVector.h"

// Define a struct to represent an edge
struct Edge {
    int neighbor;
    int weight;
};

// Define a struct to represent a vertex and its neighbors
struct Vertex {
    int id;
    CustomVector<Edge> neighbors;
};
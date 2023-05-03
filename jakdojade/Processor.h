#pragma once
#include "Point.h"
#include "CustomVector.h"
#include "CustomQueue.h"
#include "City.h"
#include "BFSPoint.h"
#include "CityDistance.h"
#include "Djikstra.h"
#include "CustomHashMap.h"

// Struct to keep track of the route
struct PQElement {
    int i;
    CustomVector<int> ids;

    PQElement(): i(0) {}
    PQElement(int i_): i(i_) {}
    bool operator<(const PQElement& other) const { return i > other.i; }

};


class Processor
{
    // Map to be loaded later
    Point **map;

    // Vector of cities
    CustomVector<City *> cities;

    // Map dimensions
    int height, width;

    // Vertices array
    CustomVector<Vertex *> vertices;

    // number of questions
    int questionCount;

public:
    Processor();

    // Get dimensions of the map
    virtual void GetDimensions();

    // Load in the map
    virtual void LoadMap();

    // Print map contents
    virtual void PrintMap();

    // Find asterisk next to a city
    virtual Point *FindAsterisk(int x, int y, CustomString &cityName);

    // Find all cities
    virtual void FindCities();

    // Print all cities
    virtual void PrintCities();

    // Return cities
    virtual CustomVector<City *>*GetCities();

    // Check if the point is in bounds of the map
    virtual bool inBounds(Point *pt);

    virtual int bfs();

    virtual CustomVector<BFSPoint *> getNeighbors(BFSPoint *p);

    virtual PQElement dijkstra(int source, int destination);

    virtual void GetFlights();

    virtual int FindCityIndex(char* name);

    virtual void GetResults();
};
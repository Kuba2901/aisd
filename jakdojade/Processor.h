#pragma once
#include "Point.h"
#include "CustomVector.h"
#include "CustomQueue.h"
#include "City.h"
#include "BFSPoint.h"
#include "CityDistance.h"


class Processor
{
    // Map to be loaded later
    Point **map;

    // Vector of cities
    CustomVector<City *> cities;

    // Map dimensions
    int height, width;

    // Vector of cities with distances
    CustomVector<CityDistance* > citiesDistance;

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

};
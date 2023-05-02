#pragma once
#include "CustomString.h"
#include "Surroundings.h"
#include "CustomVector.h"
#include "Position.h"
#include "Type.h"
#include "City.h"

class Processor
{
private:
    // Dimensions of the map
    int width, height;

    // The map
    CustomVector<Position *> **map;

    // All cities array
    CustomVector<City *> **cities;

public:
    Processor();

    // The main processor flow
    virtual void FindRoute();

    // Get and set the dimensions of the map
    virtual void GetDimensions();

    // Load in the map
    virtual void LoadMap();

    // // Gets the type of the surface
    // virtual Type *GetRoadType(Position *pos);

    // // Determines the starting position
    // virtual Position *DeterminePosition(CustomString &cityName);

    // // Find the exit route
    // virtual Position *FindAsterisk(int x, int y, CustomString &cityName);

    // // Find all citites on the map
    // virtual void FindCities();

    // // Print out cities
    // virtual void PrintCities();

    // // Check if the point is in bounds
    // virtual bool InBounds(Position *pkt);

    // // Check if the point is traversable
    // virtual bool Traversable(Position *pkt);

    // virtual CustomVector<City *> GetCities();

    // virtual void SetVisited(Position *pos, bool visited);

    // virtual int GetHeight();
    // virtual int GetWidth();
};

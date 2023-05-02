#pragma once
#include "City.h"

struct CityDistance {
    int distance;
    City* city;

    CityDistance(City* city_, int distance_) : distance(distance_), city(city_) {}
    
};
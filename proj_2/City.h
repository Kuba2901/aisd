#pragma once
#include "CustomString.h"
#include "Position.h"

class City
{
    CustomString *name;
    Position *exit;

public:
    City(CustomString *name_, Position *exit_)
    {
        this->name = name_;
        this->exit = exit_;
    }

    CustomString *GetName()
    {
        return this->name;
    }

    Position *GetPosition()
    {
        return this->exit;
    }

    void toString()
    {
        std::cout << name->GetString() << " at (" << exit->x << ", " << exit->y << ")" << std::endl;
    }
};
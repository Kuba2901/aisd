#pragma once
#include "CustomString.h"
#include "Point.h"

class City
{
    CustomString *name;
    Point *exit;

public:
    City(CustomString *name_,
         Point *exit_);

    City &operator=(const City &other)
    {
        if (this != &other)
        {
            // delete the old data
            delete name;
            delete exit;

            // perform a deep copy
            name = new CustomString(*other.name);
            exit = new Point(*other.exit);
        }
        return *this;
    }

    City(const City &other)
    {
        name = new CustomString(*other.name);
        exit = new Point(*other.exit);
    }

    void toString()
    {
        std::cout << "CITY { " << name->GetString() << ", exit: (" << exit->GetX() << ", " << exit->GetY() << ")}";
    }

    Point* GetPoint() {
        return this->exit;
    }

    CustomString* GetName() {
        return this->name;
    }
};
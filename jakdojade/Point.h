#pragma once

class Point
{
    int x, y;
    char character;
    bool visited;

public:
    Point();
    Point(int x_, int y_, char character_);
    Point(int x_, int y_, bool visited_, char character_);

    // Copy constructor
    Point(const Point &other)
        : x(other.x), y(other.y), character(other.character), visited(other.visited)
    {
    }

    // Overloaded assignment operator
    Point &operator=(const Point &other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            character = other.character;
            visited = other.visited;
        }
        return *this;
    }

    Point &operator=(const Point *other)
    {
        if (this == other)
        {
            return *this;
        }

        this->x = other->x;
        this->y = other->y;
        this->character = other->character;
        this->visited = other->visited;

        return *this;
    }

    virtual int GetX();
    virtual int GetY();
    virtual char GetCharacter();
    virtual bool GetVisited();
    virtual void SetX(int x_);
    virtual void SetY(int y_);
    virtual void SetCharacter(char character_);
    virtual void SetVisited(bool visited_);
    virtual void toString();
    
    // Moving on board
    virtual bool isTraversable();
};
#pragma once

class Position
{
public:
    int x;
    int y;
    bool visited;
    char character;

    Position()
    {
        x = -1;
        y = -1;
        visited = false;
        character = NULL;

        std::cout << "point created" << std::endl;
    }

    Position(int x_, int y_, bool visited_, char character_)
    {
        x = x_;
        y = y_;
        visited = visited_;
        character = character_;
    }

    bool valid(int height, int width)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            return true;
        }
        return false;
    }

    Position &operator=(const Position &other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            visited = other.visited;
        }
        return *this;
    }
};

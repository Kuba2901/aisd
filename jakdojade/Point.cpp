#include <iostream>
#include "Point.h"

Point::Point()
{
    this->character = 0;
    this->visited = false;
    this->x = -1;
    this->y = -1;
}


Point::Point(int x_, int y_)
{
    this->character = 0;
    this->visited = false;
    this->x = x_;
    this->y = y_;
}

Point::Point(int x_, int y_, char character_)
{
    this->visited = false;
    this->x = x_;
    this->y = y_;
    this->character = 0;
}

Point::Point(int x_, int y_, bool visited_, char character_)
{
    this->visited = visited_;
    this->x = x_;
    this->y = y_;
    this->character = character_;
}

int Point::GetX()
{
    return this->x;
}
int Point::GetY()
{
    return this->y;
}
char Point::GetCharacter()
{
    return this->character;
}
bool Point::GetVisited()
{
    return this->visited;
}

void Point::SetX(int x_)
{
    this->x = x_;
}
void Point::SetY(int y_)
{
    this->y = y_;
}
void Point::SetCharacter(char character_)
{
    this->character = character_;
}
void Point::SetVisited(bool visited_)
{
    this->visited = visited_;
}

void Point::toString()
{

    std::cout << "(" << x << ", " << y << ")";
}

bool Point::isTraversable() {
    return !(character == '.' || (character >= 65 && character <= 90));
}